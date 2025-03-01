// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from scout_mini_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_

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
// Member 'fault_state'
#include "scout_mini_msgs/msg/detail/fault_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__scout_mini_msgs__msg__RobotState __attribute__((deprecated))
#else
# define DEPRECATED__scout_mini_msgs__msg__RobotState __declspec(deprecated)
#endif

namespace scout_mini_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotState_
{
  using Type = RobotState_<ContainerAllocator>;

  explicit RobotState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    fault_state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot = "";
      this->normal_state = false;
      this->control_mode = "";
      this->battery_voltage = 0.0;
    }
  }

  explicit RobotState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    robot(_alloc),
    control_mode(_alloc),
    fault_state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot = "";
      this->normal_state = false;
      this->control_mode = "";
      this->battery_voltage = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _robot_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_type robot;
  using _normal_state_type =
    bool;
  _normal_state_type normal_state;
  using _control_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _control_mode_type control_mode;
  using _battery_voltage_type =
    double;
  _battery_voltage_type battery_voltage;
  using _fault_state_type =
    scout_mini_msgs::msg::FaultState_<ContainerAllocator>;
  _fault_state_type fault_state;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__robot(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot = _arg;
    return *this;
  }
  Type & set__normal_state(
    const bool & _arg)
  {
    this->normal_state = _arg;
    return *this;
  }
  Type & set__control_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->control_mode = _arg;
    return *this;
  }
  Type & set__battery_voltage(
    const double & _arg)
  {
    this->battery_voltage = _arg;
    return *this;
  }
  Type & set__fault_state(
    const scout_mini_msgs::msg::FaultState_<ContainerAllocator> & _arg)
  {
    this->fault_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    scout_mini_msgs::msg::RobotState_<ContainerAllocator> *;
  using ConstRawPtr =
    const scout_mini_msgs::msg::RobotState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<scout_mini_msgs::msg::RobotState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<scout_mini_msgs::msg::RobotState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      scout_mini_msgs::msg::RobotState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<scout_mini_msgs::msg::RobotState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      scout_mini_msgs::msg::RobotState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<scout_mini_msgs::msg::RobotState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<scout_mini_msgs::msg::RobotState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<scout_mini_msgs::msg::RobotState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__scout_mini_msgs__msg__RobotState
    std::shared_ptr<scout_mini_msgs::msg::RobotState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__scout_mini_msgs__msg__RobotState
    std::shared_ptr<scout_mini_msgs::msg::RobotState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->robot != other.robot) {
      return false;
    }
    if (this->normal_state != other.normal_state) {
      return false;
    }
    if (this->control_mode != other.control_mode) {
      return false;
    }
    if (this->battery_voltage != other.battery_voltage) {
      return false;
    }
    if (this->fault_state != other.fault_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotState_

// alias to use template instance with default allocator
using RobotState =
  scout_mini_msgs::msg::RobotState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_
