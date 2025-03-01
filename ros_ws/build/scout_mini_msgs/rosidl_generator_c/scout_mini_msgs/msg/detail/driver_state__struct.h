// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from scout_mini_msgs:msg/DriverState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__STRUCT_H_
#define SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__STRUCT_H_

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

/// Struct defined in msg/DriverState in the package scout_mini_msgs.
typedef struct scout_mini_msgs__msg__DriverState
{
  std_msgs__msg__Header header;
  double driver_voltage[4];
  int16_t driver_temperature[4];
  bool communication_failure[4];
  bool low_supply_voltage[4];
  bool motor_over_temperature[4];
  bool driver_over_current[4];
  bool driver_over_temperature[4];
} scout_mini_msgs__msg__DriverState;

// Struct for a sequence of scout_mini_msgs__msg__DriverState.
typedef struct scout_mini_msgs__msg__DriverState__Sequence
{
  scout_mini_msgs__msg__DriverState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scout_mini_msgs__msg__DriverState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__STRUCT_H_
