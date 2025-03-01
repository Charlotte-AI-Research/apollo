// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from scout_mini_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "scout_mini_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "scout_mini_msgs/msg/detail/robot_state__struct.hpp"

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

namespace scout_mini_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scout_mini_msgs
cdr_serialize(
  const scout_mini_msgs::msg::RobotState & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scout_mini_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  scout_mini_msgs::msg::RobotState & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scout_mini_msgs
get_serialized_size(
  const scout_mini_msgs::msg::RobotState & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scout_mini_msgs
max_serialized_size_RobotState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace scout_mini_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scout_mini_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, scout_mini_msgs, msg, RobotState)();

#ifdef __cplusplus
}
#endif

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
