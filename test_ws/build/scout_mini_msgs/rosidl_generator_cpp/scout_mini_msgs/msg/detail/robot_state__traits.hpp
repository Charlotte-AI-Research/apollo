// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from scout_mini_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "scout_mini_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'fault_state'
#include "scout_mini_msgs/msg/detail/fault_state__traits.hpp"

namespace scout_mini_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: robot
  {
    out << "robot: ";
    rosidl_generator_traits::value_to_yaml(msg.robot, out);
    out << ", ";
  }

  // member: normal_state
  {
    out << "normal_state: ";
    rosidl_generator_traits::value_to_yaml(msg.normal_state, out);
    out << ", ";
  }

  // member: control_mode
  {
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << ", ";
  }

  // member: battery_voltage
  {
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << ", ";
  }

  // member: fault_state
  {
    out << "fault_state: ";
    to_flow_style_yaml(msg.fault_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotState & msg,
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

  // member: robot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot: ";
    rosidl_generator_traits::value_to_yaml(msg.robot, out);
    out << "\n";
  }

  // member: normal_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "normal_state: ";
    rosidl_generator_traits::value_to_yaml(msg.normal_state, out);
    out << "\n";
  }

  // member: control_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << "\n";
  }

  // member: battery_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << "\n";
  }

  // member: fault_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fault_state:\n";
    to_block_style_yaml(msg.fault_state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotState & msg, bool use_flow_style = false)
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
  const scout_mini_msgs::msg::RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  scout_mini_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use scout_mini_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const scout_mini_msgs::msg::RobotState & msg)
{
  return scout_mini_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<scout_mini_msgs::msg::RobotState>()
{
  return "scout_mini_msgs::msg::RobotState";
}

template<>
inline const char * name<scout_mini_msgs::msg::RobotState>()
{
  return "scout_mini_msgs/msg/RobotState";
}

template<>
struct has_fixed_size<scout_mini_msgs::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<scout_mini_msgs::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<scout_mini_msgs::msg::RobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
