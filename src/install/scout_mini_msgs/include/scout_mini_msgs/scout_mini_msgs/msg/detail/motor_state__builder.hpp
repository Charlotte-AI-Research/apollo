// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from scout_mini_msgs:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "scout_mini_msgs/msg/detail/motor_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace scout_mini_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorState_temperature
{
public:
  explicit Init_MotorState_temperature(::scout_mini_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  ::scout_mini_msgs::msg::MotorState temperature(::scout_mini_msgs::msg::MotorState::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scout_mini_msgs::msg::MotorState msg_;
};

class Init_MotorState_current
{
public:
  explicit Init_MotorState_current(::scout_mini_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_temperature current(::scout_mini_msgs::msg::MotorState::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_MotorState_temperature(msg_);
  }

private:
  ::scout_mini_msgs::msg::MotorState msg_;
};

class Init_MotorState_velocity
{
public:
  explicit Init_MotorState_velocity(::scout_mini_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_current velocity(::scout_mini_msgs::msg::MotorState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_MotorState_current(msg_);
  }

private:
  ::scout_mini_msgs::msg::MotorState msg_;
};

class Init_MotorState_position
{
public:
  explicit Init_MotorState_position(::scout_mini_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_velocity position(::scout_mini_msgs::msg::MotorState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_MotorState_velocity(msg_);
  }

private:
  ::scout_mini_msgs::msg::MotorState msg_;
};

class Init_MotorState_name
{
public:
  explicit Init_MotorState_name(::scout_mini_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_position name(::scout_mini_msgs::msg::MotorState::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_MotorState_position(msg_);
  }

private:
  ::scout_mini_msgs::msg::MotorState msg_;
};

class Init_MotorState_header
{
public:
  Init_MotorState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorState_name header(::scout_mini_msgs::msg::MotorState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorState_name(msg_);
  }

private:
  ::scout_mini_msgs::msg::MotorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::scout_mini_msgs::msg::MotorState>()
{
  return scout_mini_msgs::msg::builder::Init_MotorState_header();
}

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
