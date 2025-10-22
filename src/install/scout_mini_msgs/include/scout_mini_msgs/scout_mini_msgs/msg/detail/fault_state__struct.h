// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from scout_mini_msgs:msg/FaultState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__STRUCT_H_
#define SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FaultState in the package scout_mini_msgs.
typedef struct scout_mini_msgs__msg__FaultState
{
  bool battery_under_voltage_failure;
  bool battery_under_voltage_alarm;
  bool loss_remote_control;
} scout_mini_msgs__msg__FaultState;

// Struct for a sequence of scout_mini_msgs__msg__FaultState.
typedef struct scout_mini_msgs__msg__FaultState__Sequence
{
  scout_mini_msgs__msg__FaultState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scout_mini_msgs__msg__FaultState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__STRUCT_H_
