/**
 * @file HelloWorldPublisher.cpp
 *
 */

#include "Generated/MyMessagePubSubTypes.hpp"

#include <chrono>
#include <thread>

#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/rtps/transport/shared_mem/SharedMemTransportDescriptor.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>

using namespace eprosima::fastdds::dds;
using namespace eprosima::fastdds::rtps;

class CustomTransportPublisher
{
private:

    MyMessage my_message_;

    DomainParticipant* participant_;

    Publisher* publisher_;

    Topic* topic_;

    DataWriter* writer_;

    TypeSupport type_;

    class PubListener : public DataWriterListener
    {
    public:

        PubListener()
            : matched_(0)
        {
        }

        ~PubListener() override
        {
        }

        void on_publication_matched(
                DataWriter* writer,
                const PublicationMatchedStatus& info) override
        {
            if (info.current_count_change == 1)
            {
                matched_ = info.total_count;
                std::cout << "Publisher matched." << std::endl;
                eprosima::fastdds::rtps::LocatorList locators;
                writer->get_sending_locators(locators);
                for (const eprosima::fastdds::rtps::Locator& locator : locators)
                {
                    print_transport_protocol(locator);
                }

            }
            else if (info.current_count_change == -1)
            {
                matched_ = info.total_count;
                std::cout << "Publisher unmatched." << std::endl;
            }
            else
            {
                std::cout << info.current_count_change
                        << " is not a valid value for PublicationMatchedStatus current count change." << std::endl;
            }
        }

        std::atomic_int matched_;
        private:
        void print_transport_protocol(const eprosima::fastdds::rtps::Locator &locator)
        {
            switch (locator.kind)
            {
            case LOCATOR_KIND_UDPv4:
                std::cout << "Using UDPv4" << std::endl;
                break;
            case LOCATOR_KIND_UDPv6:
                std::cout << "Using UDPv6" << std::endl;
                break;
            case LOCATOR_KIND_SHM:
                std::cout << "Using Shared Memory" << std::endl;
                break;
            default:
                std::cout << "Unknown Transport" << std::endl;
                break;
            }
        }

    } listener_;

public:

    CustomTransportPublisher()
        : participant_(nullptr)
        , publisher_(nullptr)
        , topic_(nullptr)
        , writer_(nullptr)
        , type_(new MyMessagePubSubType())
    {
    }

    virtual ~CustomTransportPublisher()
    {
        if (writer_ != nullptr)
        {
            publisher_->delete_datawriter(writer_);
        }
        if (publisher_ != nullptr)
        {
            participant_->delete_publisher(publisher_);
        }
        if (topic_ != nullptr)
        {
            participant_->delete_topic(topic_);
        }
        DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }

    //!Initialize the publisher
    bool init()
    {
        my_message_.index(0);

        DomainParticipantQos participantQos;
        participantQos.name("Participant_publisher");

        // // Explicit configuration of shm transport
        // participantQos.transport().use_builtin_transports = false;
        // auto shm_transport = std::make_shared<SharedMemTransportDescriptor>();
        // shm_transport->segment_size(10 * 1024 * 1024);
        // participantQos.transport().user_transports.push_back(shm_transport);

        participant_ = DomainParticipantFactory::get_instance()->create_participant(1, participantQos);

        if (participant_ == nullptr)
        {
            return false;
        }

        // Register the Type
        type_.register_type(participant_);

        // Create the publications Topic
        topic_ = participant_->create_topic("HelloWorld", type_.get_type_name(), TOPIC_QOS_DEFAULT);

        if (topic_ == nullptr)
        {
            return false;
        }

        // Create the Publisher
        publisher_ = participant_->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);

        if (publisher_ == nullptr)
        {
            return false;
        }

        // Create the DataWriter
        writer_ = publisher_->create_datawriter(topic_, DATAWRITER_QOS_DEFAULT, &listener_);

        if (writer_ == nullptr)
        {
            return false;
        }
        return true;
    }

    //!Send a publication
    bool publish()
    {
        if (listener_.matched_ > 0)
        {
            my_message_.index(my_message_.index() + 1);
            my_message_.first_number(fRand(0,20));
            my_message_.second_number(fRand(0,20));
            writer_->write(&my_message_);
            return true;
        }
        return false;
    }

    //!Run the Publisher
    void run(
            uint32_t samples)
    {
        uint32_t samples_sent = 0;
        while (samples_sent < samples)
        {
            if (publish())
            {
                samples_sent++;
                std::cout <<"#1: " << my_message_.first_number() 
                          <<" #2: "<< my_message_.second_number() 
                          <<" Index: " << my_message_.index()
                          <<" SENT" << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    double fRand(double fMin, double fMax)
    {
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }
};

int main()
{
    std::cout << "Starting publisher." << std::endl;
    uint32_t samples = 10;

    CustomTransportPublisher* mypub = new CustomTransportPublisher();
    if(mypub->init())
    {
        mypub->run(samples);
    }

    delete mypub;
    return 0;
}