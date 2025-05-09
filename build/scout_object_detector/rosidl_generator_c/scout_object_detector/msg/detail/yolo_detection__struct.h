// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from scout_object_detector:msg/YoloDetection.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_OBJECT_DETECTOR__MSG__DETAIL__YOLO_DETECTION__STRUCT_H_
#define SCOUT_OBJECT_DETECTOR__MSG__DETAIL__YOLO_DETECTION__STRUCT_H_

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

/// Struct defined in msg/YoloDetection in the package scout_object_detector.
typedef struct scout_object_detector__msg__YoloDetection
{
  int32_t id;
  rosidl_runtime_c__String class_label;
  float confidence;
  int32_t x;
  int32_t y;
  int32_t width;
  int32_t height;
} scout_object_detector__msg__YoloDetection;

// Struct for a sequence of scout_object_detector__msg__YoloDetection.
typedef struct scout_object_detector__msg__YoloDetection__Sequence
{
  scout_object_detector__msg__YoloDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} scout_object_detector__msg__YoloDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SCOUT_OBJECT_DETECTOR__MSG__DETAIL__YOLO_DETECTION__STRUCT_H_
