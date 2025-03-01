// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from scout_mini_msgs:msg/LightState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__BUILDER_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "scout_mini_msgs/msg/detail/light_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace scout_mini_msgs
{

namespace msg
{

namespace builder
{

class Init_LightState_brightness
{
public:
  explicit Init_LightState_brightness(::scout_mini_msgs::msg::LightState & msg)
  : msg_(msg)
  {}
  ::scout_mini_msgs::msg::LightState brightness(::scout_mini_msgs::msg::LightState::_brightness_type arg)
  {
    msg_.brightness = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scout_mini_msgs::msg::LightState msg_;
};

class Init_LightState_mode
{
public:
  explicit Init_LightState_mode(::scout_mini_msgs::msg::LightState & msg)
  : msg_(msg)
  {}
  Init_LightState_brightness mode(::scout_mini_msgs::msg::LightState::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_LightState_brightness(msg_);
  }

private:
  ::scout_mini_msgs::msg::LightState msg_;
};

class Init_LightState_control_enable
{
public:
  explicit Init_LightState_control_enable(::scout_mini_msgs::msg::LightState & msg)
  : msg_(msg)
  {}
  Init_LightState_mode control_enable(::scout_mini_msgs::msg::LightState::_control_enable_type arg)
  {
    msg_.control_enable = std::move(arg);
    return Init_LightState_mode(msg_);
  }

private:
  ::scout_mini_msgs::msg::LightState msg_;
};

class Init_LightState_header
{
public:
  Init_LightState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LightState_control_enable header(::scout_mini_msgs::msg::LightState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LightState_control_enable(msg_);
  }

private:
  ::scout_mini_msgs::msg::LightState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::scout_mini_msgs::msg::LightState>()
{
  return scout_mini_msgs::msg::builder::Init_LightState_header();
}

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__BUILDER_HPP_
