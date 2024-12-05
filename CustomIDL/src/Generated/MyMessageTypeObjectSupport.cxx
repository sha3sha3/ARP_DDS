// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file MyMessageTypeObjectSupport.cxx
 * Source file containing the implementation to register the TypeObject representation of the described types in the IDL file
 *
 * This file was generated by the tool fastddsgen.
 */

#include "MyMessageTypeObjectSupport.hpp"

#include <mutex>
#include <string>

#include <fastcdr/xcdr/external.hpp>
#include <fastcdr/xcdr/optional.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/log/Log.hpp>
#include <fastdds/dds/xtypes/common.hpp>
#include <fastdds/dds/xtypes/type_representation/ITypeObjectRegistry.hpp>
#include <fastdds/dds/xtypes/type_representation/TypeObject.hpp>
#include <fastdds/dds/xtypes/type_representation/TypeObjectUtils.hpp>

#include "MyMessage.hpp"


using namespace eprosima::fastdds::dds::xtypes;

// TypeIdentifier is returned by reference: dependent structures/unions are registered in this same method
void register_MyMessage_type_identifier(
        TypeIdentifierPair& type_ids_MyMessage)
{

    ReturnCode_t return_code_MyMessage {eprosima::fastdds::dds::RETCODE_OK};
    return_code_MyMessage =
        eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
        "MyMessage", type_ids_MyMessage);
    if (eprosima::fastdds::dds::RETCODE_OK != return_code_MyMessage)
    {
        StructTypeFlag struct_flags_MyMessage = TypeObjectUtils::build_struct_type_flag(eprosima::fastdds::dds::xtypes::ExtensibilityKind::APPENDABLE,
                false, false);
        QualifiedTypeName type_name_MyMessage = "MyMessage";
        eprosima::fastcdr::optional<AppliedBuiltinTypeAnnotations> type_ann_builtin_MyMessage;
        eprosima::fastcdr::optional<AppliedAnnotationSeq> ann_custom_MyMessage;
        CompleteTypeDetail detail_MyMessage = TypeObjectUtils::build_complete_type_detail(type_ann_builtin_MyMessage, ann_custom_MyMessage, type_name_MyMessage.to_string());
        CompleteStructHeader header_MyMessage;
        header_MyMessage = TypeObjectUtils::build_complete_struct_header(TypeIdentifier(), detail_MyMessage);
        CompleteStructMemberSeq member_seq_MyMessage;
        {
            TypeIdentifierPair type_ids_index;
            ReturnCode_t return_code_index {eprosima::fastdds::dds::RETCODE_OK};
            return_code_index =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_uint32_t", type_ids_index);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_index)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "index Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                return;
            }
            StructMemberFlag member_flags_index = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructFailAction::DISCARD,
                    false, false, false, false);
            MemberId member_id_index = 0x00000000;
            bool common_index_ec {false};
            CommonStructMember common_index {TypeObjectUtils::build_common_struct_member(member_id_index, member_flags_index, TypeObjectUtils::retrieve_complete_type_identifier(type_ids_index, common_index_ec))};
            if (!common_index_ec)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION, "Structure index member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_index = "index";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_index;
            ann_custom_MyMessage.reset();
            CompleteMemberDetail detail_index = TypeObjectUtils::build_complete_member_detail(name_index, member_ann_builtin_index, ann_custom_MyMessage);
            CompleteStructMember member_index = TypeObjectUtils::build_complete_struct_member(common_index, detail_index);
            TypeObjectUtils::add_complete_struct_member(member_seq_MyMessage, member_index);
        }
        {
            TypeIdentifierPair type_ids_first_number;
            ReturnCode_t return_code_first_number {eprosima::fastdds::dds::RETCODE_OK};
            return_code_first_number =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_double", type_ids_first_number);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_first_number)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "first_number Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                return;
            }
            StructMemberFlag member_flags_first_number = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructFailAction::DISCARD,
                    false, false, false, false);
            MemberId member_id_first_number = 0x00000001;
            bool common_first_number_ec {false};
            CommonStructMember common_first_number {TypeObjectUtils::build_common_struct_member(member_id_first_number, member_flags_first_number, TypeObjectUtils::retrieve_complete_type_identifier(type_ids_first_number, common_first_number_ec))};
            if (!common_first_number_ec)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION, "Structure first_number member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_first_number = "first_number";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_first_number;
            ann_custom_MyMessage.reset();
            CompleteMemberDetail detail_first_number = TypeObjectUtils::build_complete_member_detail(name_first_number, member_ann_builtin_first_number, ann_custom_MyMessage);
            CompleteStructMember member_first_number = TypeObjectUtils::build_complete_struct_member(common_first_number, detail_first_number);
            TypeObjectUtils::add_complete_struct_member(member_seq_MyMessage, member_first_number);
        }
        {
            TypeIdentifierPair type_ids_second_number;
            ReturnCode_t return_code_second_number {eprosima::fastdds::dds::RETCODE_OK};
            return_code_second_number =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_double", type_ids_second_number);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_second_number)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "second_number Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                return;
            }
            StructMemberFlag member_flags_second_number = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructFailAction::DISCARD,
                    false, false, false, false);
            MemberId member_id_second_number = 0x00000002;
            bool common_second_number_ec {false};
            CommonStructMember common_second_number {TypeObjectUtils::build_common_struct_member(member_id_second_number, member_flags_second_number, TypeObjectUtils::retrieve_complete_type_identifier(type_ids_second_number, common_second_number_ec))};
            if (!common_second_number_ec)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION, "Structure second_number member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_second_number = "second_number";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_second_number;
            ann_custom_MyMessage.reset();
            CompleteMemberDetail detail_second_number = TypeObjectUtils::build_complete_member_detail(name_second_number, member_ann_builtin_second_number, ann_custom_MyMessage);
            CompleteStructMember member_second_number = TypeObjectUtils::build_complete_struct_member(common_second_number, detail_second_number);
            TypeObjectUtils::add_complete_struct_member(member_seq_MyMessage, member_second_number);
        }
        CompleteStructType struct_type_MyMessage = TypeObjectUtils::build_complete_struct_type(struct_flags_MyMessage, header_MyMessage, member_seq_MyMessage);
        if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                TypeObjectUtils::build_and_register_struct_type_object(struct_type_MyMessage, type_name_MyMessage.to_string(), type_ids_MyMessage))
        {
            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                    "MyMessage already registered in TypeObjectRegistry for a different type.");
        }
    }
}
