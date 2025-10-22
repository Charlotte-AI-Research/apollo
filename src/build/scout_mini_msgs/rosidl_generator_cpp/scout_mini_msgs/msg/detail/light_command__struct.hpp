// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from scout_mini_msgs:msg/LightCommand.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_COMMAND__STRUCT_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__scout_mini_msgs__msg__LightCommand __attribute__((deprecated))
#else
# define DEPRECATED__scout_mini_msgs__msg__LightCommand __declspec(deprecated)
#endif

namespace scout_mini_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LightCommand_
{
  using Type = LightCommand_<ContainerAllocator>;

  explicit LightCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->brightness = 0;
    }
  }

  explicit LightCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->brightness = 0;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _brightness_type =
    uint8_t;
  _brightness_type brightness;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
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
  static constexpr uint8_t NC =
    0u;
  static constexpr uint8_t NO =
    1u;
  static constexpr uint8_t BL =
    2u;
  static constexpr uint8_t CUSTOM =
    3u;

  // pointer types
  using RawPtr =
    scout_mini_msgs::msg::LightCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const scout_mini_msgs::msg::LightCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<scout_mini_msgs::msg::LightCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<scout_mini_msgs::msg::LightCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      scout_mini_msgs::msg::LightCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<scout_mini_msgs::msg::LightCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      scout_mini_msgs::msg::LightCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<scout_mini_msgs::msg::LightCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<scout_mini_msgs::msg::LightCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<scout_mini_msgs::msg::LightCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__scout_mini_msgs__msg__LightCommand
    std::shared_ptr<scout_mini_msgs::msg::LightCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__scout_mini_msgs__msg__LightCommand
    std::shared_ptr<scout_mini_msgs::msg::LightCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LightCommand_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->brightness != other.brightness) {
      return false;
    }
    return true;
  }
  bool operator!=(const LightCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LightCommand_

// alias to use template instance with default allocator
using LightCommand =
  scout_mini_msgs::msg::LightCommand_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LightCommand_<ContainerAllocator>::NC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LightCommand_<ContainerAllocator>::NO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LightCommand_<ContainerAllocator>::BL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LightCommand_<ContainerAllocator>::CUSTOM;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace scout_mini_msgs

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_COMMAND__STRUCT_HPP_
