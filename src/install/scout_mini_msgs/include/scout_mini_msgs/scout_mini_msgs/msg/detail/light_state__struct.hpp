// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from scout_mini_msgs:msg/LightState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__STRUCT_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__STRUCT_HPP_

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
# define DEPRECATED__scout_mini_msgs__msg__LightState __attribute__((deprecated))
#else
# define DEPRECATED__scout_mini_msgs__msg__LightState __declspec(deprecated)
#endif

namespace scout_mini_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LightState_
{
  using Type = LightState_<ContainerAllocator>;

  explicit LightState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->control_enable = false;
      this->mode = "";
      this->brightness = 0;
    }
  }

  explicit LightState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->control_enable = false;
      this->mode = "";
      this->brightness = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _control_enable_type =
    bool;
  _control_enable_type control_enable;
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _brightness_type =
    uint8_t;
  _brightness_type brightness;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__control_enable(
    const bool & _arg)
  {
    this->control_enable = _arg;
    return *this;
  }
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__brightness(
    const uint8_t & _arg)
  {
    this->brightness = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    scout_mini_msgs::msg::LightState_<ContainerAllocator> *;
  using ConstRawPtr =
    const scout_mini_msgs::msg::LightState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<scout_mini_msgs::msg::LightState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<scout_mini_msgs::msg::LightState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      scout_mini_msgs::msg::LightState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<scout_mini_msgs::msg::LightState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      scout_mini_msgs::msg::LightState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<scout_mini_msgs::msg::LightState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<scout_mini_msgs::msg::LightState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<scout_mini_msgs::msg::LightState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__scout_mini_msgs__msg__LightState
    std::shared_ptr<scout_mini_msgs::msg::LightState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__scout_mini_msgs__msg__LightState
    std::shared_ptr<scout_mini_msgs::msg::LightState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LightState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->control_enable != other.control_enable) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->brightness != other.brightness) {
      return false;
    }
    return true;
  }
  bool operator!=(const LightState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LightState_

// alias to use template instance with default allocator
using LightState =
  scout_mini_msgs::msg::LightState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__STRUCT_HPP_
