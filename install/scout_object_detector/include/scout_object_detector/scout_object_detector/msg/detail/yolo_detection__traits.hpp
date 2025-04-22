// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from scout_object_detector:msg/YoloDetection.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_OBJECT_DETECTOR__MSG__DETAIL__YOLO_DETECTION__TRAITS_HPP_
#define SCOUT_OBJECT_DETECTOR__MSG__DETAIL__YOLO_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "scout_object_detector/msg/detail/yolo_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace scout_object_detector
{

namespace msg
{

inline void to_flow_style_yaml(
  const YoloDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: class_label
  {
    out << "class_label: ";
    rosidl_generator_traits::value_to_yaml(msg.class_label, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const YoloDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: class_label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_label: ";
    rosidl_generator_traits::value_to_yaml(msg.class_label, out);
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

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
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

}  // namespace scout_object_detector

namespace rosidl_generator_traits
{

[[deprecated("use scout_object_detector::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const scout_object_detector::msg::YoloDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  scout_object_detector::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use scout_object_detector::msg::to_yaml() instead")]]
inline std::string to_yaml(const scout_object_detector::msg::YoloDetection & msg)
{
  return scout_object_detector::msg::to_yaml(msg);
}

template<>
inline const char * data_type<scout_object_detector::msg::YoloDetection>()
{
  return "scout_object_detector::msg::YoloDetection";
}

template<>
inline const char * name<scout_object_detector::msg::YoloDetection>()
{
  return "scout_object_detector/msg/YoloDetection";
}

template<>
struct has_fixed_size<scout_object_detector::msg::YoloDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<scout_object_detector::msg::YoloDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<scout_object_detector::msg::YoloDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SCOUT_OBJECT_DETECTOR__MSG__DETAIL__YOLO_DETECTION__TRAITS_HPP_
