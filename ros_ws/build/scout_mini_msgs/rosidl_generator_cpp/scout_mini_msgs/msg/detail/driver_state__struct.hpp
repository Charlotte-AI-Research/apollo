// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from scout_mini_msgs:msg/DriverState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__STRUCT_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__scout_mini_msgs__msg__DriverState __attribute__((deprecated))
#else
# define DEPRECATED__scout_mini_msgs__msg__DriverState __declspec(deprecated)
#endif

namespace scout_mini_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DriverState_
{
  using Type = DriverState_<ContainerAllocator>;

  explicit DriverState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 4>::iterator, double>(this->driver_voltage.begin(), this->driver_voltage.end(), 0.0);
      std::fill<typename std::array<int16_t, 4>::iterator, int16_t>(this->driver_temperature.begin(), this->driver_temperature.end(), 0);
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->communication_failure.begin(), this->communication_failure.end(), false);
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->low_supply_voltage.begin(), this->low_supply_voltage.end(), false);
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->motor_over_temperature.begin(), this->motor_over_temperature.end(), false);
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->driver_over_current.begin(), this->driver_over_current.end(), false);
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->driver_over_temperature.begin(), this->driver_over_temperature.end(), false);
    }
  }

  explicit DriverState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    driver_voltage(_alloc),
    driver_temperature(_alloc),
    communication_failure(_alloc),
    low_supply_voltage(_alloc),
    motor_over_temperature(_alloc),
    driver_over_current(_alloc),
    driver_over_temperature(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 4>::iterator, double>(this->driver_voltage.begin(), this->driver_voltage.end(), 0.0);
      std::fill<typename std::array<int16_t, 4>::iterator, int16_t>(this->driver_temperature.begin(), this->driver_temperature.end(), 0);
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->communication_failure.begin(), this->communication_failure.end(), false);
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->low_supply_voltage.begin(), this->low_supply_voltage.end(), false);
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->motor_over_temperature.begin(), this->motor_over_temperature.end(), false);
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->driver_over_current.begin(), this->driver_over_current.end(), false);
      std::fill<typename std::array<bool, 4>::iterator, bool>(this->driver_over_temperature.begin(), this->driver_over_temperature.end(), false);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _driver_voltage_type =
    std::array<double, 4>;
  _driver_voltage_type driver_voltage;
  using _driver_temperature_type =
    std::array<int16_t, 4>;
  _driver_temperature_type driver_temperature;
  using _communication_failure_type =
    std::array<bool, 4>;
  _communication_failure_type communication_failure;
  using _low_supply_voltage_type =
    std::array<bool, 4>;
  _low_supply_voltage_type low_supply_voltage;
  using _motor_over_temperature_type =
    std::array<bool, 4>;
  _motor_over_temperature_type motor_over_temperature;
  using _driver_over_current_type =
    std::array<bool, 4>;
  _driver_over_current_type driver_over_current;
  using _driver_over_temperature_type =
    std::array<bool, 4>;
  _driver_over_temperature_type driver_over_temperature;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__driver_voltage(
    const std::array<double, 4> & _arg)
  {
    this->driver_voltage = _arg;
    return *this;
  }
  Type & set__driver_temperature(
    const std::array<int16_t, 4> & _arg)
  {
    this->driver_temperature = _arg;
    return *this;
  }
  Type & set__communication_failure(
    const std::array<bool, 4> & _arg)
  {
    this->communication_failure = _arg;
    return *this;
  }
  Type & set__low_supply_voltage(
    const std::array<bool, 4> & _arg)
  {
    this->low_supply_voltage = _arg;
    return *this;
  }
  Type & set__motor_over_temperature(
    const std::array<bool, 4> & _arg)
  {
    this->motor_over_temperature = _arg;
    return *this;
  }
  Type & set__driver_over_current(
    const std::array<bool, 4> & _arg)
  {
    this->driver_over_current = _arg;
    return *this;
  }
  Type & set__driver_over_temperature(
    const std::array<bool, 4> & _arg)
  {
    this->driver_over_temperature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    scout_mini_msgs::msg::DriverState_<ContainerAllocator> *;
  using ConstRawPtr =
    const scout_mini_msgs::msg::DriverState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<scout_mini_msgs::msg::DriverState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<scout_mini_msgs::msg::DriverState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      scout_mini_msgs::msg::DriverState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<scout_mini_msgs::msg::DriverState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      scout_mini_msgs::msg::DriverState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<scout_mini_msgs::msg::DriverState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<scout_mini_msgs::msg::DriverState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<scout_mini_msgs::msg::DriverState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__scout_mini_msgs__msg__DriverState
    std::shared_ptr<scout_mini_msgs::msg::DriverState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__scout_mini_msgs__msg__DriverState
    std::shared_ptr<scout_mini_msgs::msg::DriverState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DriverState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->driver_voltage != other.driver_voltage) {
      return false;
    }
    if (this->driver_temperature != other.driver_temperature) {
      return false;
    }
    if (this->communication_failure != other.communication_failure) {
      return false;
    }
    if (this->low_supply_voltage != other.low_supply_voltage) {
      return false;
    }
    if (this->motor_over_temperature != other.motor_over_temperature) {
      return false;
    }
    if (this->driver_over_current != other.driver_over_current) {
      return false;
    }
    if (this->driver_over_temperature != other.driver_over_temperature) {
      return false;
    }
    return true;
  }
  bool operator!=(const DriverState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DriverState_

// alias to use template instance with default allocator
using DriverState =
  scout_mini_msgs::msg::DriverState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__STRUCT_HPP_
