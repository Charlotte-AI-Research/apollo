// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from scout_mini_msgs:msg/FaultState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__BUILDER_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "scout_mini_msgs/msg/detail/fault_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace scout_mini_msgs
{

namespace msg
{

namespace builder
{

class Init_FaultState_loss_remote_control
{
public:
  explicit Init_FaultState_loss_remote_control(::scout_mini_msgs::msg::FaultState & msg)
  : msg_(msg)
  {}
  ::scout_mini_msgs::msg::FaultState loss_remote_control(::scout_mini_msgs::msg::FaultState::_loss_remote_control_type arg)
  {
    msg_.loss_remote_control = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scout_mini_msgs::msg::FaultState msg_;
};

class Init_FaultState_battery_under_voltage_alarm
{
public:
  explicit Init_FaultState_battery_under_voltage_alarm(::scout_mini_msgs::msg::FaultState & msg)
  : msg_(msg)
  {}
  Init_FaultState_loss_remote_control battery_under_voltage_alarm(::scout_mini_msgs::msg::FaultState::_battery_under_voltage_alarm_type arg)
  {
    msg_.battery_under_voltage_alarm = std::move(arg);
    return Init_FaultState_loss_remote_control(msg_);
  }

private:
  ::scout_mini_msgs::msg::FaultState msg_;
};

class Init_FaultState_battery_under_voltage_failure
{
public:
  Init_FaultState_battery_under_voltage_failure()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FaultState_battery_under_voltage_alarm battery_under_voltage_failure(::scout_mini_msgs::msg::FaultState::_battery_under_voltage_failure_type arg)
  {
    msg_.battery_under_voltage_failure = std::move(arg);
    return Init_FaultState_battery_under_voltage_alarm(msg_);
  }

private:
  ::scout_mini_msgs::msg::FaultState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::scout_mini_msgs::msg::FaultState>()
{
  return scout_mini_msgs::msg::builder::Init_FaultState_battery_under_voltage_failure();
}

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__BUILDER_HPP_
