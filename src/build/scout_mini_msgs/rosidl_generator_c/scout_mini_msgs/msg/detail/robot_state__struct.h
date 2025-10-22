// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from scout_mini_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
#define SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'robot'
// Member 'control_mode'
#include "rosidl_runtime_c/string.h"
// Member 'fault_state'
#include "scout_mini_msgs/msg/detail/fault_state__struct.h"

/// Struct defined in msg/RobotState in the package scout_mini_msgs.
typedef struct scout_mini_msgs__msg__RobotState
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String robot;
  bool normal_state;
  /// IDLE, CAN, SERIAL, REMOTE, NONE
  rosidl_runtime_c__String control_mode;
  double battery_voltage;
  scout_mini_msgs__msg__FaultState fault_state;
} scout_mini_msgs__msg__RobotState;

// Struct for a sequence of scout_mini_msgs__msg__RobotState.
typedef struct scout_mini_msgs__msg__RobotState__Sequence
{
  scout_mini_msgs__msg__RobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scout_mini_msgs__msg__RobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
