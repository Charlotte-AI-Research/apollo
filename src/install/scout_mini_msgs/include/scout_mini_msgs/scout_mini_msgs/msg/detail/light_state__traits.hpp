// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from scout_mini_msgs:msg/LightState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__TRAITS_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "scout_mini_msgs/msg/detail/light_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace scout_mini_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LightState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: control_enable
  {
    out << "control_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.control_enable, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: brightness
  {
    out << "brightness: ";
    rosidl_generator_traits::value_to_yaml(msg.brightness, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LightState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: control_enable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.control_enable, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: brightness
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "brightness: ";
    rosidl_generator_traits::value_to_yaml(msg.brightness, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LightState & msg, bool use_flow_style = false)
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

}  // namespace scout_mini_msgs

namespace rosidl_generator_traits
{

[[deprecated("use scout_mini_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const scout_mini_msgs::msg::LightState & msg,
  std::ostream & out, size_t indentation = 0)
{
  scout_mini_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use scout_mini_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const scout_mini_msgs::msg::LightState & msg)
{
  return scout_mini_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<scout_mini_msgs::msg::LightState>()
{
  return "scout_mini_msgs::msg::LightState";
}

template<>
inline const char * name<scout_mini_msgs::msg::LightState>()
{
  return "scout_mini_msgs/msg/LightState";
}

template<>
struct has_fixed_size<scout_mini_msgs::msg::LightState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<scout_mini_msgs::msg::LightState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<scout_mini_msgs::msg::LightState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__TRAITS_HPP_
