// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_detector:msg/YoloDetection.idl
// generated code does not contain a copyright notice

#ifndef TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__STRUCT_HPP_
#define TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__test_detector__msg__YoloDetection __attribute__((deprecated))
#else
# define DEPRECATED__test_detector__msg__YoloDetection __declspec(deprecated)
#endif

namespace test_detector
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct YoloDetection_
{
  using Type = YoloDetection_<ContainerAllocator>;

  explicit YoloDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_id = 0l;
      this->confidence = 0.0f;
      this->xmin = 0.0f;
      this->ymin = 0.0f;
      this->xmax = 0.0f;
      this->ymax = 0.0f;
    }
  }

  explicit YoloDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_id = 0l;
      this->confidence = 0.0f;
      this->xmin = 0.0f;
      this->ymin = 0.0f;
      this->xmax = 0.0f;
      this->ymax = 0.0f;
    }
  }

  // field types and members
  using _class_id_type =
    int32_t;
  _class_id_type class_id;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _xmin_type =
    float;
  _xmin_type xmin;
  using _ymin_type =
    float;
  _ymin_type ymin;
  using _xmax_type =
    float;
  _xmax_type xmax;
  using _ymax_type =
    float;
  _ymax_type ymax;

  // setters for named parameter idiom
  Type & set__class_id(
    const int32_t & _arg)
  {
    this->class_id = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__xmin(
    const float & _arg)
  {
    this->xmin = _arg;
    return *this;
  }
  Type & set__ymin(
    const float & _arg)
  {
    this->ymin = _arg;
    return *this;
  }
  Type & set__xmax(
    const float & _arg)
  {
    this->xmax = _arg;
    return *this;
  }
  Type & set__ymax(
    const float & _arg)
  {
    this->ymax = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_detector::msg::YoloDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_detector::msg::YoloDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_detector::msg::YoloDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_detector::msg::YoloDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_detector::msg::YoloDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_detector::msg::YoloDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_detector::msg::YoloDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_detector::msg::YoloDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_detector::msg::YoloDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_detector::msg::YoloDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_detector__msg__YoloDetection
    std::shared_ptr<test_detector::msg::YoloDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_detector__msg__YoloDetection
    std::shared_ptr<test_detector::msg::YoloDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloDetection_ & other) const
  {
    if (this->class_id != other.class_id) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->xmin != other.xmin) {
      return false;
    }
    if (this->ymin != other.ymin) {
      return false;
    }
    if (this->xmax != other.xmax) {
      return false;
    }
    if (this->ymax != other.ymax) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloDetection_

// alias to use template instance with default allocator
using YoloDetection =
  test_detector::msg::YoloDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_detector

#endif  // TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__STRUCT_HPP_
