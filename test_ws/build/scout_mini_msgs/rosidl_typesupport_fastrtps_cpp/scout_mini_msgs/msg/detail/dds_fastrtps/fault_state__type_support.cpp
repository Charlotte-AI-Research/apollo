// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from scout_mini_msgs:msg/FaultState.idl
// generated code does not contain a copyright notice
#include "scout_mini_msgs/msg/detail/fault_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "scout_mini_msgs/msg/detail/fault_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace scout_mini_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scout_mini_msgs
cdr_serialize(
  const scout_mini_msgs::msg::FaultState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: battery_under_voltage_failure
  cdr << (ros_message.battery_under_voltage_failure ? true : false);
  // Member: battery_under_voltage_alarm
  cdr << (ros_message.battery_under_voltage_alarm ? true : false);
  // Member: loss_remote_control
  cdr << (ros_message.loss_remote_control ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scout_mini_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  scout_mini_msgs::msg::FaultState & ros_message)
{
  // Member: battery_under_voltage_failure
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.battery_under_voltage_failure = tmp ? true : false;
  }

  // Member: battery_under_voltage_alarm
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.battery_under_voltage_alarm = tmp ? true : false;
  }

  // Member: loss_remote_control
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.loss_remote_control = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scout_mini_msgs
get_serialized_size(
  const scout_mini_msgs::msg::FaultState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: battery_under_voltage_failure
  {
    size_t item_size = sizeof(ros_message.battery_under_voltage_failure);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: battery_under_voltage_alarm
  {
    size_t item_size = sizeof(ros_message.battery_under_voltage_alarm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: loss_remote_control
  {
    size_t item_size = sizeof(ros_message.loss_remote_control);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_scout_mini_msgs
max_serialized_size_FaultState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: battery_under_voltage_failure
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: battery_under_voltage_alarm
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: loss_remote_control
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = scout_mini_msgs::msg::FaultState;
    is_plain =
      (
      offsetof(DataType, loss_remote_control) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _FaultState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const scout_mini_msgs::msg::FaultState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FaultState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<scout_mini_msgs::msg::FaultState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FaultState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const scout_mini_msgs::msg::FaultState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FaultState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FaultState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FaultState__callbacks = {
  "scout_mini_msgs::msg",
  "FaultState",
  _FaultState__cdr_serialize,
  _FaultState__cdr_deserialize,
  _FaultState__get_serialized_size,
  _FaultState__max_serialized_size
};

static rosidl_message_type_support_t _FaultState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FaultState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace scout_mini_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_scout_mini_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<scout_mini_msgs::msg::FaultState>()
{
  return &scout_mini_msgs::msg::typesupport_fastrtps_cpp::_FaultState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, scout_mini_msgs, msg, FaultState)() {
  return &scout_mini_msgs::msg::typesupport_fastrtps_cpp::_FaultState__handle;
}

#ifdef __cplusplus
}
#endif
