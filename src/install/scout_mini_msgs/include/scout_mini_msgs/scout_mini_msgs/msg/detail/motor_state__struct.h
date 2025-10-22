// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from scout_mini_msgs:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__MOTOR_STATE__STRUCT_H_
#define SCOUT_MINI_MSGS__MSG__DETAIL__MOTOR_STATE__STRUCT_H_

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
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MotorState in the package scout_mini_msgs.
typedef struct scout_mini_msgs__msg__MotorState
{
  std_msgs__msg__Header header;
  /// Joint name
  rosidl_runtime_c__String name[4];
  /// The actual position by the encoder value (rad)
  double position[4];
  /// The actual velocity measured by the encoder as the actual RPM value (rad/s)
  double velocity[4];
  /// The current flowing through the motor (A)
  double current[4];
  /// The actual temperature of motor (C)
  int16_t temperature[4];
} scout_mini_msgs__msg__MotorState;

// Struct for a sequence of scout_mini_msgs__msg__MotorState.
typedef struct scout_mini_msgs__msg__MotorState__Sequence
{
  scout_mini_msgs__msg__MotorState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scout_mini_msgs__msg__MotorState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__MOTOR_STATE__STRUCT_H_
