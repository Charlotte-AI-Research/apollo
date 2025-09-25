// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from realsense2_camera_msgs:srv/CalibConfigWrite.idl
// generated code does not contain a copyright notice

#ifndef REALSENSE2_CAMERA_MSGS__SRV__DETAIL__CALIB_CONFIG_WRITE__BUILDER_HPP_
#define REALSENSE2_CAMERA_MSGS__SRV__DETAIL__CALIB_CONFIG_WRITE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "realsense2_camera_msgs/srv/detail/calib_config_write__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace realsense2_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_CalibConfigWrite_Request_calib_config
{
public:
  Init_CalibConfigWrite_Request_calib_config()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::realsense2_camera_msgs::srv::CalibConfigWrite_Request calib_config(::realsense2_camera_msgs::srv::CalibConfigWrite_Request::_calib_config_type arg)
  {
    msg_.calib_config = std::move(arg);
    return std::move(msg_);
  }

private:
  ::realsense2_camera_msgs::srv::CalibConfigWrite_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::realsense2_camera_msgs::srv::CalibConfigWrite_Request>()
{
  return realsense2_camera_msgs::srv::builder::Init_CalibConfigWrite_Request_calib_config();
}

}  // namespace realsense2_camera_msgs


namespace realsense2_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_CalibConfigWrite_Response_error_message
{
public:
  explicit Init_CalibConfigWrite_Response_error_message(::realsense2_camera_msgs::srv::CalibConfigWrite_Response & msg)
  : msg_(msg)
  {}
  ::realsense2_camera_msgs::srv::CalibConfigWrite_Response error_message(::realsense2_camera_msgs::srv::CalibConfigWrite_Response::_error_message_type arg)
  {
    msg_.error_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::realsense2_camera_msgs::srv::CalibConfigWrite_Response msg_;
};

class Init_CalibConfigWrite_Response_success
{
public:
  Init_CalibConfigWrite_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalibConfigWrite_Response_error_message success(::realsense2_camera_msgs::srv::CalibConfigWrite_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_CalibConfigWrite_Response_error_message(msg_);
  }

private:
  ::realsense2_camera_msgs::srv::CalibConfigWrite_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::realsense2_camera_msgs::srv::CalibConfigWrite_Response>()
{
  return realsense2_camera_msgs::srv::builder::Init_CalibConfigWrite_Response_success();
}

}  // namespace realsense2_camera_msgs

#endif  // REALSENSE2_CAMERA_MSGS__SRV__DETAIL__CALIB_CONFIG_WRITE__BUILDER_HPP_
