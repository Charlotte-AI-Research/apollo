// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from follow_human:msg/DepthEstimation.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__STRUCT_HPP_
#define FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__follow_human__msg__DepthEstimation __attribute__((deprecated))
#else
# define DEPRECATED__follow_human__msg__DepthEstimation __declspec(deprecated)
#endif

namespace follow_human
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DepthEstimation_
{
  using Type = DepthEstimation_<ContainerAllocator>;

  explicit DepthEstimation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->class_label = "";
      this->confidence = 0.0f;
      this->x = 0l;
      this->y = 0l;
      this->width = 0l;
      this->height = 0l;
      this->depth_m = 0.0f;
    }
  }

  explicit DepthEstimation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : class_label(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->class_label = "";
      this->confidence = 0.0f;
      this->x = 0l;
      this->y = 0l;
      this->width = 0l;
      this->height = 0l;
      this->depth_m = 0.0f;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _class_label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_label_type class_label;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _x_type =
    int32_t;
  _x_type x;
  using _y_type =
    int32_t;
  _y_type y;
  using _width_type =
    int32_t;
  _width_type width;
  using _height_type =
    int32_t;
  _height_type height;
  using _depth_m_type =
    float;
  _depth_m_type depth_m;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__class_label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_label = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__x(
    const int32_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int32_t & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__width(
    const int32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const int32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__depth_m(
    const float & _arg)
  {
    this->depth_m = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_human::msg::DepthEstimation_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_human::msg::DepthEstimation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_human::msg::DepthEstimation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_human::msg::DepthEstimation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_human::msg::DepthEstimation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_human::msg::DepthEstimation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_human::msg::DepthEstimation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_human::msg::DepthEstimation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_human::msg::DepthEstimation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_human::msg::DepthEstimation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_human__msg__DepthEstimation
    std::shared_ptr<follow_human::msg::DepthEstimation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_human__msg__DepthEstimation
    std::shared_ptr<follow_human::msg::DepthEstimation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DepthEstimation_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->class_label != other.class_label) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->depth_m != other.depth_m) {
      return false;
    }
    return true;
  }
  bool operator!=(const DepthEstimation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DepthEstimation_

// alias to use template instance with default allocator
using DepthEstimation =
  follow_human::msg::DepthEstimation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace follow_human

#endif  // FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__STRUCT_HPP_
