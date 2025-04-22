// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_detector:msg/YoloDetection.idl
// generated code does not contain a copyright notice

#ifndef TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__STRUCT_H_
#define TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/YoloDetection in the package test_detector.
typedef struct test_detector__msg__YoloDetection
{
  int32_t class_id;
  float confidence;
  float xmin;
  float ymin;
  float xmax;
  float ymax;
} test_detector__msg__YoloDetection;

// Struct for a sequence of test_detector__msg__YoloDetection.
typedef struct test_detector__msg__YoloDetection__Sequence
{
  test_detector__msg__YoloDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_detector__msg__YoloDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__STRUCT_H_
