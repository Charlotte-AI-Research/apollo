// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from scout_mini_msgs:msg/LightCommand.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_COMMAND__STRUCT_H_
#define SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'NC'.
enum
{
  scout_mini_msgs__msg__LightCommand__NC = 0
};

/// Constant 'NO'.
enum
{
  scout_mini_msgs__msg__LightCommand__NO = 1
};

/// Constant 'BL'.
enum
{
  scout_mini_msgs__msg__LightCommand__BL = 2
};

/// Constant 'CUSTOM'.
enum
{
  scout_mini_msgs__msg__LightCommand__CUSTOM = 3
};

/// Struct defined in msg/LightCommand in the package scout_mini_msgs.
typedef struct scout_mini_msgs__msg__LightCommand
{
  /// Lighting Mode
  uint8_t mode;
  /// Only for CUSTOM mode
  uint8_t brightness;
} scout_mini_msgs__msg__LightCommand;

// Struct for a sequence of scout_mini_msgs__msg__LightCommand.
typedef struct scout_mini_msgs__msg__LightCommand__Sequence
{
  scout_mini_msgs__msg__LightCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scout_mini_msgs__msg__LightCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_COMMAND__STRUCT_H_
