// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from scout_mini_msgs:msg/LightCommand.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_COMMAND__BUILDER_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "scout_mini_msgs/msg/detail/light_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace scout_mini_msgs
{

namespace msg
{

namespace builder
{

class Init_LightCommand_brightness
{
public:
  explicit Init_LightCommand_brightness(::scout_mini_msgs::msg::LightCommand & msg)
  : msg_(msg)
  {}
  ::scout_mini_msgs::msg::LightCommand brightness(::scout_mini_msgs::msg::LightCommand::_brightness_type arg)
  {
    msg_.brightness = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scout_mini_msgs::msg::LightCommand msg_;
};

class Init_LightCommand_mode
{
public:
  Init_LightCommand_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LightCommand_brightness mode(::scout_mini_msgs::msg::LightCommand::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_LightCommand_brightness(msg_);
  }

private:
  ::scout_mini_msgs::msg::LightCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::scout_mini_msgs::msg::LightCommand>()
{
  return scout_mini_msgs::msg::builder::Init_LightCommand_mode();
}

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_COMMAND__BUILDER_HPP_
