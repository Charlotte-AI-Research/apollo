// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rslidar_msg:msg/RslidarPacket.idl
// generated code does not contain a copyright notice

#ifndef RSLIDAR_MSG__MSG__DETAIL__RSLIDAR_PACKET__STRUCT_H_
#define RSLIDAR_MSG__MSG__DETAIL__RSLIDAR_PACKET__STRUCT_H_

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
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RslidarPacket in the package rslidar_msg.
typedef struct rslidar_msg__msg__RslidarPacket
{
  std_msgs__msg__Header header;
  uint8_t is_difop;
  uint8_t is_frame_begin;
  rosidl_runtime_c__uint8__Sequence data;
} rslidar_msg__msg__RslidarPacket;

// Struct for a sequence of rslidar_msg__msg__RslidarPacket.
typedef struct rslidar_msg__msg__RslidarPacket__Sequence
{
  rslidar_msg__msg__RslidarPacket * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rslidar_msg__msg__RslidarPacket__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RSLIDAR_MSG__MSG__DETAIL__RSLIDAR_PACKET__STRUCT_H_
