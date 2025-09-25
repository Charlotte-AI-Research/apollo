// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from follow_human:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_HUMAN__MSG__DETAIL__TRACKED_OBJECT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define FOLLOW_HUMAN__MSG__DETAIL__TRACKED_OBJECT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "follow_human/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "follow_human/msg/detail/tracked_object__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace follow_human
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_follow_human
cdr_serialize(
  const follow_human::msg::TrackedObject & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_follow_human
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  follow_human::msg::TrackedObject & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_follow_human
get_serialized_size(
  const follow_human::msg::TrackedObject & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_follow_human
max_serialized_size_TrackedObject(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace follow_human

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_follow_human
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, follow_human, msg, TrackedObject)();

#ifdef __cplusplus
}
#endif

#endif  // FOLLOW_HUMAN__MSG__DETAIL__TRACKED_OBJECT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
