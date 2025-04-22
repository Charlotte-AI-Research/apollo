// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from follow_human:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_HUMAN__MSG__DETAIL__TRACKED_OBJECT__TRAITS_HPP_
#define FOLLOW_HUMAN__MSG__DETAIL__TRACKED_OBJECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "follow_human/msg/detail/tracked_object__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace follow_human
{

namespace msg
{

inline void to_flow_style_yaml(
  const TrackedObject & msg,
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
  const TrackedObject & msg,
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

inline std::string to_yaml(const TrackedObject & msg, bool use_flow_style = false)
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

}  // namespace follow_human

namespace rosidl_generator_traits
{

[[deprecated("use follow_human::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_human::msg::TrackedObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_human::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_human::msg::to_yaml() instead")]]
inline std::string to_yaml(const follow_human::msg::TrackedObject & msg)
{
  return follow_human::msg::to_yaml(msg);
}

template<>
inline const char * data_type<follow_human::msg::TrackedObject>()
{
  return "follow_human::msg::TrackedObject";
}

template<>
inline const char * name<follow_human::msg::TrackedObject>()
{
  return "follow_human/msg/TrackedObject";
}

template<>
struct has_fixed_size<follow_human::msg::TrackedObject>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<follow_human::msg::TrackedObject>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<follow_human::msg::TrackedObject>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FOLLOW_HUMAN__MSG__DETAIL__TRACKED_OBJECT__TRAITS_HPP_
