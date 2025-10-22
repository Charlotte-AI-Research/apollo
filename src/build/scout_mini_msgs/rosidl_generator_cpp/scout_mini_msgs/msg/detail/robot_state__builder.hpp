// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from scout_mini_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "scout_mini_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace scout_mini_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotState_fault_state
{
public:
  explicit Init_RobotState_fault_state(::scout_mini_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::scout_mini_msgs::msg::RobotState fault_state(::scout_mini_msgs::msg::RobotState::_fault_state_type arg)
  {
    msg_.fault_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scout_mini_msgs::msg::RobotState msg_;
};

class Init_RobotState_battery_voltage
{
public:
  explicit Init_RobotState_battery_voltage(::scout_mini_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_fault_state battery_voltage(::scout_mini_msgs::msg::RobotState::_battery_voltage_type arg)
  {
    msg_.battery_voltage = std::move(arg);
    return Init_RobotState_fault_state(msg_);
  }

private:
  ::scout_mini_msgs::msg::RobotState msg_;
};

class Init_RobotState_control_mode
{
public:
  explicit Init_RobotState_control_mode(::scout_mini_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_battery_voltage control_mode(::scout_mini_msgs::msg::RobotState::_control_mode_type arg)
  {
    msg_.control_mode = std::move(arg);
    return Init_RobotState_battery_voltage(msg_);
  }

private:
  ::scout_mini_msgs::msg::RobotState msg_;
};

class Init_RobotState_normal_state
{
public:
  explicit Init_RobotState_normal_state(::scout_mini_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_control_mode normal_state(::scout_mini_msgs::msg::RobotState::_normal_state_type arg)
  {
    msg_.normal_state = std::move(arg);
    return Init_RobotState_control_mode(msg_);
  }

private:
  ::scout_mini_msgs::msg::RobotState msg_;
};

class Init_RobotState_robot
{
public:
  explicit Init_RobotState_robot(::scout_mini_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_normal_state robot(::scout_mini_msgs::msg::RobotState::_robot_type arg)
  {
    msg_.robot = std::move(arg);
    return Init_RobotState_normal_state(msg_);
  }

private:
  ::scout_mini_msgs::msg::RobotState msg_;
};

class Init_RobotState_header
{
public:
  Init_RobotState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_robot header(::scout_mini_msgs::msg::RobotState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RobotState_robot(msg_);
  }

private:
  ::scout_mini_msgs::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::scout_mini_msgs::msg::RobotState>()
{
  return scout_mini_msgs::msg::builder::Init_RobotState_header();
}

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
