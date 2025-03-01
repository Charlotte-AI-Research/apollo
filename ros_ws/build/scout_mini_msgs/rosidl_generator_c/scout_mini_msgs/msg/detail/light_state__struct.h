// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from scout_mini_msgs:msg/LightState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__STRUCT_H_
#define SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__STRUCT_H_

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
// Member 'mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/LightState in the package scout_mini_msgs.
typedef struct scout_mini_msgs__msg__LightState
{
  std_msgs__msg__Header header;
  /// Lighting control enable flag
  bool control_enable;
  /// The current mode (ON, OFF, BL, CUSTOM)
  rosidl_runtime_c__String mode;
  /// The current brightness of light (0 - 100)
  uint8_t brightness;
} scout_mini_msgs__msg__LightState;

// Struct for a sequence of scout_mini_msgs__msg__LightState.
typedef struct scout_mini_msgs__msg__LightState__Sequence
{
  scout_mini_msgs__msg__LightState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scout_mini_msgs__msg__LightState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__STRUCT_H_
