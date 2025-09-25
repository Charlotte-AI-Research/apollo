// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from scout_mini_msgs:msg/FaultState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__TRAITS_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "scout_mini_msgs/msg/detail/fault_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace scout_mini_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FaultState & msg,
  std::ostream & out)
{
  out << "{";
  // member: battery_under_voltage_failure
  {
    out << "battery_under_voltage_failure: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_under_voltage_failure, out);
    out << ", ";
  }

  // member: battery_under_voltage_alarm
  {
    out << "battery_under_voltage_alarm: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_under_voltage_alarm, out);
    out << ", ";
  }

  // member: loss_remote_control
  {
    out << "loss_remote_control: ";
    rosidl_generator_traits::value_to_yaml(msg.loss_remote_control, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FaultState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: battery_under_voltage_failure
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_under_voltage_failure: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_under_voltage_failure, out);
    out << "\n";
  }

  // member: battery_under_voltage_alarm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_under_voltage_alarm: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_under_voltage_alarm, out);
    out << "\n";
  }

  // member: loss_remote_control
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "loss_remote_control: ";
    rosidl_generator_traits::value_to_yaml(msg.loss_remote_control, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FaultState & msg, bool use_flow_style = false)
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
  const scout_mini_msgs::msg::FaultState & msg,
  std::ostream & out, size_t indentation = 0)
{
  scout_mini_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use scout_mini_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const scout_mini_msgs::msg::FaultState & msg)
{
  return scout_mini_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<scout_mini_msgs::msg::FaultState>()
{
  return "scout_mini_msgs::msg::FaultState";
}

template<>
inline const char * name<scout_mini_msgs::msg::FaultState>()
{
  return "scout_mini_msgs/msg/FaultState";
}

template<>
struct has_fixed_size<scout_mini_msgs::msg::FaultState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<scout_mini_msgs::msg::FaultState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<scout_mini_msgs::msg::FaultState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__TRAITS_HPP_
