// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from realsense2_camera_msgs:action/TriggeredCalibration.idl
// generated code does not contain a copyright notice

#ifndef REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__STRUCT_HPP_
#define REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Goal __attribute__((deprecated))
#else
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Goal __declspec(deprecated)
#endif

namespace realsense2_camera_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TriggeredCalibration_Goal_
{
  using Type = TriggeredCalibration_Goal_<ContainerAllocator>;

  explicit TriggeredCalibration_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->json = "calib run";
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->json = "";
    }
  }

  explicit TriggeredCalibration_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : json(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->json = "calib run";
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->json = "";
    }
  }

  // field types and members
  using _json_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _json_type json;

  // setters for named parameter idiom
  Type & set__json(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->json = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Goal
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Goal
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggeredCalibration_Goal_ & other) const
  {
    if (this->json != other.json) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggeredCalibration_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggeredCalibration_Goal_

// alias to use template instance with default allocator
using TriggeredCalibration_Goal =
  realsense2_camera_msgs::action::TriggeredCalibration_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace realsense2_camera_msgs


#ifndef _WIN32
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Result __attribute__((deprecated))
#else
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Result __declspec(deprecated)
#endif

namespace realsense2_camera_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TriggeredCalibration_Result_
{
  using Type = TriggeredCalibration_Result_<ContainerAllocator>;

  explicit TriggeredCalibration_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_msg = "";
      this->calibration = "";
      this->health = 0.0f;
    }
  }

  explicit TriggeredCalibration_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error_msg(_alloc),
    calibration(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_msg = "";
      this->calibration = "";
      this->health = 0.0f;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _error_msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_msg_type error_msg;
  using _calibration_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _calibration_type calibration;
  using _health_type =
    float;
  _health_type health;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__error_msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error_msg = _arg;
    return *this;
  }
  Type & set__calibration(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->calibration = _arg;
    return *this;
  }
  Type & set__health(
    const float & _arg)
  {
    this->health = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Result
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Result
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggeredCalibration_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->error_msg != other.error_msg) {
      return false;
    }
    if (this->calibration != other.calibration) {
      return false;
    }
    if (this->health != other.health) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggeredCalibration_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggeredCalibration_Result_

// alias to use template instance with default allocator
using TriggeredCalibration_Result =
  realsense2_camera_msgs::action::TriggeredCalibration_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace realsense2_camera_msgs


#ifndef _WIN32
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Feedback __declspec(deprecated)
#endif

namespace realsense2_camera_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TriggeredCalibration_Feedback_
{
  using Type = TriggeredCalibration_Feedback_<ContainerAllocator>;

  explicit TriggeredCalibration_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->progress = 0.0f;
    }
  }

  explicit TriggeredCalibration_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->progress = 0.0f;
    }
  }

  // field types and members
  using _progress_type =
    float;
  _progress_type progress;

  // setters for named parameter idiom
  Type & set__progress(
    const float & _arg)
  {
    this->progress = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Feedback
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_Feedback
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggeredCalibration_Feedback_ & other) const
  {
    if (this->progress != other.progress) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggeredCalibration_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggeredCalibration_Feedback_

// alias to use template instance with default allocator
using TriggeredCalibration_Feedback =
  realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace realsense2_camera_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "realsense2_camera_msgs/action/detail/triggered_calibration__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request __declspec(deprecated)
#endif

namespace realsense2_camera_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TriggeredCalibration_SendGoal_Request_
{
  using Type = TriggeredCalibration_SendGoal_Request_<ContainerAllocator>;

  explicit TriggeredCalibration_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit TriggeredCalibration_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const realsense2_camera_msgs::action::TriggeredCalibration_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggeredCalibration_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggeredCalibration_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggeredCalibration_SendGoal_Request_

// alias to use template instance with default allocator
using TriggeredCalibration_SendGoal_Request =
  realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace realsense2_camera_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response __declspec(deprecated)
#endif

namespace realsense2_camera_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TriggeredCalibration_SendGoal_Response_
{
  using Type = TriggeredCalibration_SendGoal_Response_<ContainerAllocator>;

  explicit TriggeredCalibration_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit TriggeredCalibration_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggeredCalibration_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggeredCalibration_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggeredCalibration_SendGoal_Response_

// alias to use template instance with default allocator
using TriggeredCalibration_SendGoal_Response =
  realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace realsense2_camera_msgs

namespace realsense2_camera_msgs
{

namespace action
{

struct TriggeredCalibration_SendGoal
{
  using Request = realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request;
  using Response = realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response;
};

}  // namespace action

}  // namespace realsense2_camera_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request __declspec(deprecated)
#endif

namespace realsense2_camera_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TriggeredCalibration_GetResult_Request_
{
  using Type = TriggeredCalibration_GetResult_Request_<ContainerAllocator>;

  explicit TriggeredCalibration_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit TriggeredCalibration_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggeredCalibration_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggeredCalibration_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggeredCalibration_GetResult_Request_

// alias to use template instance with default allocator
using TriggeredCalibration_GetResult_Request =
  realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace realsense2_camera_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "realsense2_camera_msgs/action/detail/triggered_calibration__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response __declspec(deprecated)
#endif

namespace realsense2_camera_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TriggeredCalibration_GetResult_Response_
{
  using Type = TriggeredCalibration_GetResult_Response_<ContainerAllocator>;

  explicit TriggeredCalibration_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit TriggeredCalibration_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const realsense2_camera_msgs::action::TriggeredCalibration_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggeredCalibration_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggeredCalibration_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggeredCalibration_GetResult_Response_

// alias to use template instance with default allocator
using TriggeredCalibration_GetResult_Response =
  realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace realsense2_camera_msgs

namespace realsense2_camera_msgs
{

namespace action
{

struct TriggeredCalibration_GetResult
{
  using Request = realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request;
  using Response = realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response;
};

}  // namespace action

}  // namespace realsense2_camera_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "realsense2_camera_msgs/action/detail/triggered_calibration__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage __declspec(deprecated)
#endif

namespace realsense2_camera_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TriggeredCalibration_FeedbackMessage_
{
  using Type = TriggeredCalibration_FeedbackMessage_<ContainerAllocator>;

  explicit TriggeredCalibration_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit TriggeredCalibration_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const realsense2_camera_msgs::action::TriggeredCalibration_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage
    std::shared_ptr<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggeredCalibration_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggeredCalibration_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggeredCalibration_FeedbackMessage_

// alias to use template instance with default allocator
using TriggeredCalibration_FeedbackMessage =
  realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace realsense2_camera_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace realsense2_camera_msgs
{

namespace action
{

struct TriggeredCalibration
{
  /// The goal message defined in the action definition.
  using Goal = realsense2_camera_msgs::action::TriggeredCalibration_Goal;
  /// The result message defined in the action definition.
  using Result = realsense2_camera_msgs::action::TriggeredCalibration_Result;
  /// The feedback message defined in the action definition.
  using Feedback = realsense2_camera_msgs::action::TriggeredCalibration_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = realsense2_camera_msgs::action::TriggeredCalibration_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = realsense2_camera_msgs::action::TriggeredCalibration_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct TriggeredCalibration TriggeredCalibration;

}  // namespace action

}  // namespace realsense2_camera_msgs

#endif  // REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__STRUCT_HPP_
