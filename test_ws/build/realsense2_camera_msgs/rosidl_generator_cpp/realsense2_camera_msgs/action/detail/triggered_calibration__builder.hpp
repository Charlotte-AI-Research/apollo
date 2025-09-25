// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from realsense2_camera_msgs:action/TriggeredCalibration.idl
// generated code does not contain a copyright notice

#ifndef REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__BUILDER_HPP_
#define REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "realsense2_camera_msgs/action/detail/triggered_calibration__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace realsense2_camera_msgs
{

namespace action
{

namespace builder
{

class Init_TriggeredCalibration_Goal_json
{
public:
  Init_TriggeredCalibration_Goal_json()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::realsense2_camera_msgs::action::TriggeredCalibration_Goal json(::realsense2_camera_msgs::action::TriggeredCalibration_Goal::_json_type arg)
  {
    msg_.json = std::move(arg);
    return std::move(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::realsense2_camera_msgs::action::TriggeredCalibration_Goal>()
{
  return realsense2_camera_msgs::action::builder::Init_TriggeredCalibration_Goal_json();
}

}  // namespace realsense2_camera_msgs


namespace realsense2_camera_msgs
{

namespace action
{

namespace builder
{

class Init_TriggeredCalibration_Result_health
{
public:
  explicit Init_TriggeredCalibration_Result_health(::realsense2_camera_msgs::action::TriggeredCalibration_Result & msg)
  : msg_(msg)
  {}
  ::realsense2_camera_msgs::action::TriggeredCalibration_Result health(::realsense2_camera_msgs::action::TriggeredCalibration_Result::_health_type arg)
  {
    msg_.health = std::move(arg);
    return std::move(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_Result msg_;
};

class Init_TriggeredCalibration_Result_calibration
{
public:
  explicit Init_TriggeredCalibration_Result_calibration(::realsense2_camera_msgs::action::TriggeredCalibration_Result & msg)
  : msg_(msg)
  {}
  Init_TriggeredCalibration_Result_health calibration(::realsense2_camera_msgs::action::TriggeredCalibration_Result::_calibration_type arg)
  {
    msg_.calibration = std::move(arg);
    return Init_TriggeredCalibration_Result_health(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_Result msg_;
};

class Init_TriggeredCalibration_Result_error_msg
{
public:
  explicit Init_TriggeredCalibration_Result_error_msg(::realsense2_camera_msgs::action::TriggeredCalibration_Result & msg)
  : msg_(msg)
  {}
  Init_TriggeredCalibration_Result_calibration error_msg(::realsense2_camera_msgs::action::TriggeredCalibration_Result::_error_msg_type arg)
  {
    msg_.error_msg = std::move(arg);
    return Init_TriggeredCalibration_Result_calibration(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_Result msg_;
};

class Init_TriggeredCalibration_Result_success
{
public:
  Init_TriggeredCalibration_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TriggeredCalibration_Result_error_msg success(::realsense2_camera_msgs::action::TriggeredCalibration_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_TriggeredCalibration_Result_error_msg(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::realsense2_camera_msgs::action::TriggeredCalibration_Result>()
{
  return realsense2_camera_msgs::action::builder::Init_TriggeredCalibration_Result_success();
}

}  // namespace realsense2_camera_msgs


namespace realsense2_camera_msgs
{

namespace action
{

namespace builder
{

class Init_TriggeredCalibration_Feedback_progress
{
public:
  Init_TriggeredCalibration_Feedback_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::realsense2_camera_msgs::action::TriggeredCalibration_Feedback progress(::realsense2_camera_msgs::action::TriggeredCalibration_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::realsense2_camera_msgs::action::TriggeredCalibration_Feedback>()
{
  return realsense2_camera_msgs::action::builder::Init_TriggeredCalibration_Feedback_progress();
}

}  // namespace realsense2_camera_msgs


namespace realsense2_camera_msgs
{

namespace action
{

namespace builder
{

class Init_TriggeredCalibration_SendGoal_Request_goal
{
public:
  explicit Init_TriggeredCalibration_SendGoal_Request_goal(::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request goal(::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request msg_;
};

class Init_TriggeredCalibration_SendGoal_Request_goal_id
{
public:
  Init_TriggeredCalibration_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TriggeredCalibration_SendGoal_Request_goal goal_id(::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_TriggeredCalibration_SendGoal_Request_goal(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request>()
{
  return realsense2_camera_msgs::action::builder::Init_TriggeredCalibration_SendGoal_Request_goal_id();
}

}  // namespace realsense2_camera_msgs


namespace realsense2_camera_msgs
{

namespace action
{

namespace builder
{

class Init_TriggeredCalibration_SendGoal_Response_stamp
{
public:
  explicit Init_TriggeredCalibration_SendGoal_Response_stamp(::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response stamp(::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response msg_;
};

class Init_TriggeredCalibration_SendGoal_Response_accepted
{
public:
  Init_TriggeredCalibration_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TriggeredCalibration_SendGoal_Response_stamp accepted(::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_TriggeredCalibration_SendGoal_Response_stamp(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response>()
{
  return realsense2_camera_msgs::action::builder::Init_TriggeredCalibration_SendGoal_Response_accepted();
}

}  // namespace realsense2_camera_msgs


namespace realsense2_camera_msgs
{

namespace action
{

namespace builder
{

class Init_TriggeredCalibration_GetResult_Request_goal_id
{
public:
  Init_TriggeredCalibration_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request goal_id(::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request>()
{
  return realsense2_camera_msgs::action::builder::Init_TriggeredCalibration_GetResult_Request_goal_id();
}

}  // namespace realsense2_camera_msgs


namespace realsense2_camera_msgs
{

namespace action
{

namespace builder
{

class Init_TriggeredCalibration_GetResult_Response_result
{
public:
  explicit Init_TriggeredCalibration_GetResult_Response_result(::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response result(::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response msg_;
};

class Init_TriggeredCalibration_GetResult_Response_status
{
public:
  Init_TriggeredCalibration_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TriggeredCalibration_GetResult_Response_result status(::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_TriggeredCalibration_GetResult_Response_result(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response>()
{
  return realsense2_camera_msgs::action::builder::Init_TriggeredCalibration_GetResult_Response_status();
}

}  // namespace realsense2_camera_msgs


namespace realsense2_camera_msgs
{

namespace action
{

namespace builder
{

class Init_TriggeredCalibration_FeedbackMessage_feedback
{
public:
  explicit Init_TriggeredCalibration_FeedbackMessage_feedback(::realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage feedback(::realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage msg_;
};

class Init_TriggeredCalibration_FeedbackMessage_goal_id
{
public:
  Init_TriggeredCalibration_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TriggeredCalibration_FeedbackMessage_feedback goal_id(::realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_TriggeredCalibration_FeedbackMessage_feedback(msg_);
  }

private:
  ::realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage>()
{
  return realsense2_camera_msgs::action::builder::Init_TriggeredCalibration_FeedbackMessage_goal_id();
}

}  // namespace realsense2_camera_msgs

#endif  // REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__BUILDER_HPP_
