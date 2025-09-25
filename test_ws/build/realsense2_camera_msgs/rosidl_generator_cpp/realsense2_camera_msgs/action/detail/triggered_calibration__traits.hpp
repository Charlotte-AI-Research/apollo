// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from realsense2_camera_msgs:action/TriggeredCalibration.idl
// generated code does not contain a copyright notice

#ifndef REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__TRAITS_HPP_
#define REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "realsense2_camera_msgs/action/detail/triggered_calibration__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace realsense2_camera_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TriggeredCalibration_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: json
  {
    out << "json: ";
    rosidl_generator_traits::value_to_yaml(msg.json, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TriggeredCalibration_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: json
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "json: ";
    rosidl_generator_traits::value_to_yaml(msg.json, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TriggeredCalibration_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace realsense2_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use realsense2_camera_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const realsense2_camera_msgs::action::TriggeredCalibration_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  realsense2_camera_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use realsense2_camera_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const realsense2_camera_msgs::action::TriggeredCalibration_Goal & msg)
{
  return realsense2_camera_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<realsense2_camera_msgs::action::TriggeredCalibration_Goal>()
{
  return "realsense2_camera_msgs::action::TriggeredCalibration_Goal";
}

template<>
inline const char * name<realsense2_camera_msgs::action::TriggeredCalibration_Goal>()
{
  return "realsense2_camera_msgs/action/TriggeredCalibration_Goal";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<realsense2_camera_msgs::action::TriggeredCalibration_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace realsense2_camera_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TriggeredCalibration_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: error_msg
  {
    out << "error_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.error_msg, out);
    out << ", ";
  }

  // member: calibration
  {
    out << "calibration: ";
    rosidl_generator_traits::value_to_yaml(msg.calibration, out);
    out << ", ";
  }

  // member: health
  {
    out << "health: ";
    rosidl_generator_traits::value_to_yaml(msg.health, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TriggeredCalibration_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: error_msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.error_msg, out);
    out << "\n";
  }

  // member: calibration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "calibration: ";
    rosidl_generator_traits::value_to_yaml(msg.calibration, out);
    out << "\n";
  }

  // member: health
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "health: ";
    rosidl_generator_traits::value_to_yaml(msg.health, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TriggeredCalibration_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace realsense2_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use realsense2_camera_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const realsense2_camera_msgs::action::TriggeredCalibration_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  realsense2_camera_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use realsense2_camera_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const realsense2_camera_msgs::action::TriggeredCalibration_Result & msg)
{
  return realsense2_camera_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<realsense2_camera_msgs::action::TriggeredCalibration_Result>()
{
  return "realsense2_camera_msgs::action::TriggeredCalibration_Result";
}

template<>
inline const char * name<realsense2_camera_msgs::action::TriggeredCalibration_Result>()
{
  return "realsense2_camera_msgs/action/TriggeredCalibration_Result";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<realsense2_camera_msgs::action::TriggeredCalibration_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace realsense2_camera_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TriggeredCalibration_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: progress
  {
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TriggeredCalibration_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TriggeredCalibration_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace realsense2_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use realsense2_camera_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const realsense2_camera_msgs::action::TriggeredCalibration_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  realsense2_camera_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use realsense2_camera_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const realsense2_camera_msgs::action::TriggeredCalibration_Feedback & msg)
{
  return realsense2_camera_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<realsense2_camera_msgs::action::TriggeredCalibration_Feedback>()
{
  return "realsense2_camera_msgs::action::TriggeredCalibration_Feedback";
}

template<>
inline const char * name<realsense2_camera_msgs::action::TriggeredCalibration_Feedback>()
{
  return "realsense2_camera_msgs/action/TriggeredCalibration_Feedback";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<realsense2_camera_msgs::action::TriggeredCalibration_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "realsense2_camera_msgs/action/detail/triggered_calibration__traits.hpp"

namespace realsense2_camera_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TriggeredCalibration_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TriggeredCalibration_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TriggeredCalibration_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace realsense2_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use realsense2_camera_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  realsense2_camera_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use realsense2_camera_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request & msg)
{
  return realsense2_camera_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request>()
{
  return "realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request";
}

template<>
inline const char * name<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request>()
{
  return "realsense2_camera_msgs/action/TriggeredCalibration_SendGoal_Request";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace realsense2_camera_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TriggeredCalibration_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TriggeredCalibration_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TriggeredCalibration_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace realsense2_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use realsense2_camera_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  realsense2_camera_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use realsense2_camera_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response & msg)
{
  return realsense2_camera_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response>()
{
  return "realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response";
}

template<>
inline const char * name<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response>()
{
  return "realsense2_camera_msgs/action/TriggeredCalibration_SendGoal_Response";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal>()
{
  return "realsense2_camera_msgs::action::TriggeredCalibration_SendGoal";
}

template<>
inline const char * name<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal>()
{
  return "realsense2_camera_msgs/action/TriggeredCalibration_SendGoal";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request>::value &&
    has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request>::value &&
    has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<realsense2_camera_msgs::action::TriggeredCalibration_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace realsense2_camera_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TriggeredCalibration_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TriggeredCalibration_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TriggeredCalibration_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace realsense2_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use realsense2_camera_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  realsense2_camera_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use realsense2_camera_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request & msg)
{
  return realsense2_camera_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request>()
{
  return "realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request";
}

template<>
inline const char * name<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request>()
{
  return "realsense2_camera_msgs/action/TriggeredCalibration_GetResult_Request";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "realsense2_camera_msgs/action/detail/triggered_calibration__traits.hpp"

namespace realsense2_camera_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TriggeredCalibration_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TriggeredCalibration_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TriggeredCalibration_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace realsense2_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use realsense2_camera_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  realsense2_camera_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use realsense2_camera_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response & msg)
{
  return realsense2_camera_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response>()
{
  return "realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response";
}

template<>
inline const char * name<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response>()
{
  return "realsense2_camera_msgs/action/TriggeredCalibration_GetResult_Response";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_Result>::value> {};

template<>
struct has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_Result>::value> {};

template<>
struct is_message<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<realsense2_camera_msgs::action::TriggeredCalibration_GetResult>()
{
  return "realsense2_camera_msgs::action::TriggeredCalibration_GetResult";
}

template<>
inline const char * name<realsense2_camera_msgs::action::TriggeredCalibration_GetResult>()
{
  return "realsense2_camera_msgs/action/TriggeredCalibration_GetResult";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request>::value &&
    has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request>::value &&
    has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response>::value
  >
{
};

template<>
struct is_service<realsense2_camera_msgs::action::TriggeredCalibration_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<realsense2_camera_msgs::action::TriggeredCalibration_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "realsense2_camera_msgs/action/detail/triggered_calibration__traits.hpp"

namespace realsense2_camera_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TriggeredCalibration_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TriggeredCalibration_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TriggeredCalibration_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace realsense2_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use realsense2_camera_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  realsense2_camera_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use realsense2_camera_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage & msg)
{
  return realsense2_camera_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage>()
{
  return "realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage";
}

template<>
inline const char * name<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage>()
{
  return "realsense2_camera_msgs/action/TriggeredCalibration_FeedbackMessage";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<realsense2_camera_msgs::action::TriggeredCalibration_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<realsense2_camera_msgs::action::TriggeredCalibration_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<realsense2_camera_msgs::action::TriggeredCalibration_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<realsense2_camera_msgs::action::TriggeredCalibration>
  : std::true_type
{
};

template<>
struct is_action_goal<realsense2_camera_msgs::action::TriggeredCalibration_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<realsense2_camera_msgs::action::TriggeredCalibration_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<realsense2_camera_msgs::action::TriggeredCalibration_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__TRAITS_HPP_
