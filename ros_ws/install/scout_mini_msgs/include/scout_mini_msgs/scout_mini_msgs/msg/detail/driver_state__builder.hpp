// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from scout_mini_msgs:msg/DriverState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__BUILDER_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "scout_mini_msgs/msg/detail/driver_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace scout_mini_msgs
{

namespace msg
{

namespace builder
{

class Init_DriverState_driver_over_temperature
{
public:
  explicit Init_DriverState_driver_over_temperature(::scout_mini_msgs::msg::DriverState & msg)
  : msg_(msg)
  {}
  ::scout_mini_msgs::msg::DriverState driver_over_temperature(::scout_mini_msgs::msg::DriverState::_driver_over_temperature_type arg)
  {
    msg_.driver_over_temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scout_mini_msgs::msg::DriverState msg_;
};

class Init_DriverState_driver_over_current
{
public:
  explicit Init_DriverState_driver_over_current(::scout_mini_msgs::msg::DriverState & msg)
  : msg_(msg)
  {}
  Init_DriverState_driver_over_temperature driver_over_current(::scout_mini_msgs::msg::DriverState::_driver_over_current_type arg)
  {
    msg_.driver_over_current = std::move(arg);
    return Init_DriverState_driver_over_temperature(msg_);
  }

private:
  ::scout_mini_msgs::msg::DriverState msg_;
};

class Init_DriverState_motor_over_temperature
{
public:
  explicit Init_DriverState_motor_over_temperature(::scout_mini_msgs::msg::DriverState & msg)
  : msg_(msg)
  {}
  Init_DriverState_driver_over_current motor_over_temperature(::scout_mini_msgs::msg::DriverState::_motor_over_temperature_type arg)
  {
    msg_.motor_over_temperature = std::move(arg);
    return Init_DriverState_driver_over_current(msg_);
  }

private:
  ::scout_mini_msgs::msg::DriverState msg_;
};

class Init_DriverState_low_supply_voltage
{
public:
  explicit Init_DriverState_low_supply_voltage(::scout_mini_msgs::msg::DriverState & msg)
  : msg_(msg)
  {}
  Init_DriverState_motor_over_temperature low_supply_voltage(::scout_mini_msgs::msg::DriverState::_low_supply_voltage_type arg)
  {
    msg_.low_supply_voltage = std::move(arg);
    return Init_DriverState_motor_over_temperature(msg_);
  }

private:
  ::scout_mini_msgs::msg::DriverState msg_;
};

class Init_DriverState_communication_failure
{
public:
  explicit Init_DriverState_communication_failure(::scout_mini_msgs::msg::DriverState & msg)
  : msg_(msg)
  {}
  Init_DriverState_low_supply_voltage communication_failure(::scout_mini_msgs::msg::DriverState::_communication_failure_type arg)
  {
    msg_.communication_failure = std::move(arg);
    return Init_DriverState_low_supply_voltage(msg_);
  }

private:
  ::scout_mini_msgs::msg::DriverState msg_;
};

class Init_DriverState_driver_temperature
{
public:
  explicit Init_DriverState_driver_temperature(::scout_mini_msgs::msg::DriverState & msg)
  : msg_(msg)
  {}
  Init_DriverState_communication_failure driver_temperature(::scout_mini_msgs::msg::DriverState::_driver_temperature_type arg)
  {
    msg_.driver_temperature = std::move(arg);
    return Init_DriverState_communication_failure(msg_);
  }

private:
  ::scout_mini_msgs::msg::DriverState msg_;
};

class Init_DriverState_driver_voltage
{
public:
  explicit Init_DriverState_driver_voltage(::scout_mini_msgs::msg::DriverState & msg)
  : msg_(msg)
  {}
  Init_DriverState_driver_temperature driver_voltage(::scout_mini_msgs::msg::DriverState::_driver_voltage_type arg)
  {
    msg_.driver_voltage = std::move(arg);
    return Init_DriverState_driver_temperature(msg_);
  }

private:
  ::scout_mini_msgs::msg::DriverState msg_;
};

class Init_DriverState_header
{
public:
  Init_DriverState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriverState_driver_voltage header(::scout_mini_msgs::msg::DriverState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DriverState_driver_voltage(msg_);
  }

private:
  ::scout_mini_msgs::msg::DriverState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::scout_mini_msgs::msg::DriverState>()
{
  return scout_mini_msgs::msg::builder::Init_DriverState_header();
}

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__BUILDER_HPP_
