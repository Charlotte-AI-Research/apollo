// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_detector:msg/YoloDetection.idl
// generated code does not contain a copyright notice

#ifndef TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__TRAITS_HPP_
#define TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "test_detector/msg/detail/yolo_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace test_detector
{

namespace msg
{

inline void to_flow_style_yaml(
  const YoloDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: class_id
  {
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: xmin
  {
    out << "xmin: ";
    rosidl_generator_traits::value_to_yaml(msg.xmin, out);
    out << ", ";
  }

  // member: ymin
  {
    out << "ymin: ";
    rosidl_generator_traits::value_to_yaml(msg.ymin, out);
    out << ", ";
  }

  // member: xmax
  {
    out << "xmax: ";
    rosidl_generator_traits::value_to_yaml(msg.xmax, out);
    out << ", ";
  }

  // member: ymax
  {
    out << "ymax: ";
    rosidl_generator_traits::value_to_yaml(msg.ymax, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const YoloDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: class_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: xmin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xmin: ";
    rosidl_generator_traits::value_to_yaml(msg.xmin, out);
    out << "\n";
  }

  // member: ymin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ymin: ";
    rosidl_generator_traits::value_to_yaml(msg.ymin, out);
    out << "\n";
  }

  // member: xmax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xmax: ";
    rosidl_generator_traits::value_to_yaml(msg.xmax, out);
    out << "\n";
  }

  // member: ymax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ymax: ";
    rosidl_generator_traits::value_to_yaml(msg.ymax, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const YoloDetection & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace test_detector

namespace rosidl_generator_traits
{

[[deprecated("use test_detector::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const test_detector::msg::YoloDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  test_detector::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use test_detector::msg::to_yaml() instead")]]
inline std::string to_yaml(const test_detector::msg::YoloDetection & msg)
{
  return test_detector::msg::to_yaml(msg);
}

template<>
inline const char * data_type<test_detector::msg::YoloDetection>()
{
  return "test_detector::msg::YoloDetection";
}

template<>
inline const char * name<test_detector::msg::YoloDetection>()
{
  return "test_detector/msg/YoloDetection";
}

template<>
struct has_fixed_size<test_detector::msg::YoloDetection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<test_detector::msg::YoloDetection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<test_detector::msg::YoloDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__TRAITS_HPP_
