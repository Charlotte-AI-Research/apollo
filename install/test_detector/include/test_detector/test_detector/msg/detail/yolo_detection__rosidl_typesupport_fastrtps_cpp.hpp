// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from test_detector:msg/YoloDetection.idl
// generated code does not contain a copyright notice

#ifndef TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "test_detector/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "test_detector/msg/detail/yolo_detection__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace test_detector
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_detector
cdr_serialize(
  const test_detector::msg::YoloDetection & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_detector
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  test_detector::msg::YoloDetection & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_detector
get_serialized_size(
  const test_detector::msg::YoloDetection & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_detector
max_serialized_size_YoloDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace test_detector

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_detector
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, test_detector, msg, YoloDetection)();

#ifdef __cplusplus
}
#endif

#endif  // TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
