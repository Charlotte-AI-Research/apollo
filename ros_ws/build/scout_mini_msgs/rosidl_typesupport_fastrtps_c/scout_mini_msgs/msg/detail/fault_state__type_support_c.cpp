// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from scout_mini_msgs:msg/FaultState.idl
// generated code does not contain a copyright notice
#include "scout_mini_msgs/msg/detail/fault_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "scout_mini_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "scout_mini_msgs/msg/detail/fault_state__struct.h"
#include "scout_mini_msgs/msg/detail/fault_state__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _FaultState__ros_msg_type = scout_mini_msgs__msg__FaultState;

static bool _FaultState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FaultState__ros_msg_type * ros_message = static_cast<const _FaultState__ros_msg_type *>(untyped_ros_message);
  // Field name: battery_under_voltage_failure
  {
    cdr << (ros_message->battery_under_voltage_failure ? true : false);
  }

  // Field name: battery_under_voltage_alarm
  {
    cdr << (ros_message->battery_under_voltage_alarm ? true : false);
  }

  // Field name: loss_remote_control
  {
    cdr << (ros_message->loss_remote_control ? true : false);
  }

  return true;
}

static bool _FaultState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FaultState__ros_msg_type * ros_message = static_cast<_FaultState__ros_msg_type *>(untyped_ros_message);
  // Field name: battery_under_voltage_failure
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->battery_under_voltage_failure = tmp ? true : false;
  }

  // Field name: battery_under_voltage_alarm
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->battery_under_voltage_alarm = tmp ? true : false;
  }

  // Field name: loss_remote_control
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->loss_remote_control = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scout_mini_msgs
size_t get_serialized_size_scout_mini_msgs__msg__FaultState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FaultState__ros_msg_type * ros_message = static_cast<const _FaultState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name battery_under_voltage_failure
  {
    size_t item_size = sizeof(ros_message->battery_under_voltage_failure);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_under_voltage_alarm
  {
    size_t item_size = sizeof(ros_message->battery_under_voltage_alarm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name loss_remote_control
  {
    size_t item_size = sizeof(ros_message->loss_remote_control);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FaultState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_scout_mini_msgs__msg__FaultState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_scout_mini_msgs
size_t max_serialized_size_scout_mini_msgs__msg__FaultState(
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

  // member: battery_under_voltage_failure
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: battery_under_voltage_alarm
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: loss_remote_control
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
    using DataType = scout_mini_msgs__msg__FaultState;
    is_plain =
      (
      offsetof(DataType, loss_remote_control) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FaultState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_scout_mini_msgs__msg__FaultState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FaultState = {
  "scout_mini_msgs::msg",
  "FaultState",
  _FaultState__cdr_serialize,
  _FaultState__cdr_deserialize,
  _FaultState__get_serialized_size,
  _FaultState__max_serialized_size
};

static rosidl_message_type_support_t _FaultState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FaultState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, scout_mini_msgs, msg, FaultState)() {
  return &_FaultState__type_support;
}

#if defined(__cplusplus)
}
#endif
