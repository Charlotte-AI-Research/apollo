// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from scout_mini_msgs:msg/FaultState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__STRUCT_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__scout_mini_msgs__msg__FaultState __attribute__((deprecated))
#else
# define DEPRECATED__scout_mini_msgs__msg__FaultState __declspec(deprecated)
#endif

namespace scout_mini_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FaultState_
{
  using Type = FaultState_<ContainerAllocator>;

  explicit FaultState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery_under_voltage_failure = false;
      this->battery_under_voltage_alarm = false;
      this->loss_remote_control = false;
    }
  }

  explicit FaultState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery_under_voltage_failure = false;
      this->battery_under_voltage_alarm = false;
      this->loss_remote_control = false;
    }
  }

  // field types and members
  using _battery_under_voltage_failure_type =
    bool;
  _battery_under_voltage_failure_type battery_under_voltage_failure;
  using _battery_under_voltage_alarm_type =
    bool;
  _battery_under_voltage_alarm_type battery_under_voltage_alarm;
  using _loss_remote_control_type =
    bool;
  _loss_remote_control_type loss_remote_control;

  // setters for named parameter idiom
  Type & set__battery_under_voltage_failure(
    const bool & _arg)
  {
    this->battery_under_voltage_failure = _arg;
    return *this;
  }
  Type & set__battery_under_voltage_alarm(
    const bool & _arg)
  {
    this->battery_under_voltage_alarm = _arg;
    return *this;
  }
  Type & set__loss_remote_control(
    const bool & _arg)
  {
    this->loss_remote_control = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    scout_mini_msgs::msg::FaultState_<ContainerAllocator> *;
  using ConstRawPtr =
    const scout_mini_msgs::msg::FaultState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<scout_mini_msgs::msg::FaultState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<scout_mini_msgs::msg::FaultState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      scout_mini_msgs::msg::FaultState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<scout_mini_msgs::msg::FaultState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      scout_mini_msgs::msg::FaultState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<scout_mini_msgs::msg::FaultState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<scout_mini_msgs::msg::FaultState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<scout_mini_msgs::msg::FaultState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__scout_mini_msgs__msg__FaultState
    std::shared_ptr<scout_mini_msgs::msg::FaultState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__scout_mini_msgs__msg__FaultState
    std::shared_ptr<scout_mini_msgs::msg::FaultState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FaultState_ & other) const
  {
    if (this->battery_under_voltage_failure != other.battery_under_voltage_failure) {
      return false;
    }
    if (this->battery_under_voltage_alarm != other.battery_under_voltage_alarm) {
      return false;
    }
    if (this->loss_remote_control != other.loss_remote_control) {
      return false;
    }
    return true;
  }
  bool operator!=(const FaultState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FaultState_

// alias to use template instance with default allocator
using FaultState =
  scout_mini_msgs::msg::FaultState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__FAULT_STATE__STRUCT_HPP_
