// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from realsense2_camera_msgs:srv/CalibConfigRead.idl
// generated code does not contain a copyright notice

#ifndef REALSENSE2_CAMERA_MSGS__SRV__DETAIL__CALIB_CONFIG_READ__STRUCT_HPP_
#define REALSENSE2_CAMERA_MSGS__SRV__DETAIL__CALIB_CONFIG_READ__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__realsense2_camera_msgs__srv__CalibConfigRead_Request __attribute__((deprecated))
#else
# define DEPRECATED__realsense2_camera_msgs__srv__CalibConfigRead_Request __declspec(deprecated)
#endif

namespace realsense2_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CalibConfigRead_Request_
{
  using Type = CalibConfigRead_Request_<ContainerAllocator>;

  explicit CalibConfigRead_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit CalibConfigRead_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__realsense2_camera_msgs__srv__CalibConfigRead_Request
    std::shared_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__realsense2_camera_msgs__srv__CalibConfigRead_Request
    std::shared_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibConfigRead_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibConfigRead_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibConfigRead_Request_

// alias to use template instance with default allocator
using CalibConfigRead_Request =
  realsense2_camera_msgs::srv::CalibConfigRead_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace realsense2_camera_msgs


#ifndef _WIN32
# define DEPRECATED__realsense2_camera_msgs__srv__CalibConfigRead_Response __attribute__((deprecated))
#else
# define DEPRECATED__realsense2_camera_msgs__srv__CalibConfigRead_Response __declspec(deprecated)
#endif

namespace realsense2_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CalibConfigRead_Response_
{
  using Type = CalibConfigRead_Response_<ContainerAllocator>;

  explicit CalibConfigRead_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_message = "";
      this->calib_config = "";
    }
  }

  explicit CalibConfigRead_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error_message(_alloc),
    calib_config(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_message = "";
      this->calib_config = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _error_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_message_type error_message;
  using _calib_config_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _calib_config_type calib_config;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__error_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error_message = _arg;
    return *this;
  }
  Type & set__calib_config(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->calib_config = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__realsense2_camera_msgs__srv__CalibConfigRead_Response
    std::shared_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__realsense2_camera_msgs__srv__CalibConfigRead_Response
    std::shared_ptr<realsense2_camera_msgs::srv::CalibConfigRead_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibConfigRead_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->error_message != other.error_message) {
      return false;
    }
    if (this->calib_config != other.calib_config) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibConfigRead_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibConfigRead_Response_

// alias to use template instance with default allocator
using CalibConfigRead_Response =
  realsense2_camera_msgs::srv::CalibConfigRead_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace realsense2_camera_msgs

namespace realsense2_camera_msgs
{

namespace srv
{

struct CalibConfigRead
{
  using Request = realsense2_camera_msgs::srv::CalibConfigRead_Request;
  using Response = realsense2_camera_msgs::srv::CalibConfigRead_Response;
};

}  // namespace srv

}  // namespace realsense2_camera_msgs

#endif  // REALSENSE2_CAMERA_MSGS__SRV__DETAIL__CALIB_CONFIG_READ__STRUCT_HPP_
