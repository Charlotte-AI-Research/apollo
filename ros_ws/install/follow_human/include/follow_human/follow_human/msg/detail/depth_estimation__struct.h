// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from follow_human:msg/DepthEstimation.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__STRUCT_H_
#define FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'class_label'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DepthEstimation in the package follow_human.
typedef struct follow_human__msg__DepthEstimation
{
  int32_t id;
  rosidl_runtime_c__String class_label;
  float confidence;
  int32_t x;
  int32_t y;
  int32_t width;
  int32_t height;
  float depth_m;
} follow_human__msg__DepthEstimation;

// Struct for a sequence of follow_human__msg__DepthEstimation.
typedef struct follow_human__msg__DepthEstimation__Sequence
{
  follow_human__msg__DepthEstimation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_human__msg__DepthEstimation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__STRUCT_H_
