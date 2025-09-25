// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from realsense2_camera_msgs:srv/CalibConfigRead.idl
// generated code does not contain a copyright notice

#ifndef REALSENSE2_CAMERA_MSGS__SRV__DETAIL__CALIB_CONFIG_READ__TRAITS_HPP_
#define REALSENSE2_CAMERA_MSGS__SRV__DETAIL__CALIB_CONFIG_READ__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "realsense2_camera_msgs/srv/detail/calib_config_read__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace realsense2_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CalibConfigRead_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CalibConfigRead_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CalibConfigRead_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace realsense2_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use realsense2_camera_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const realsense2_camera_msgs::srv::CalibConfigRead_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  realsense2_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use realsense2_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const realsense2_camera_msgs::srv::CalibConfigRead_Request & msg)
{
  return realsense2_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<realsense2_camera_msgs::srv::CalibConfigRead_Request>()
{
  return "realsense2_camera_msgs::srv::CalibConfigRead_Request";
}

template<>
inline const char * name<realsense2_camera_msgs::srv::CalibConfigRead_Request>()
{
  return "realsense2_camera_msgs/srv/CalibConfigRead_Request";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::srv::CalibConfigRead_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<realsense2_camera_msgs::srv::CalibConfigRead_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<realsense2_camera_msgs::srv::CalibConfigRead_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace realsense2_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CalibConfigRead_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: error_message
  {
    out << "error_message: ";
    rosidl_generator_traits::value_to_yaml(msg.error_message, out);
    out << ", ";
  }

  // member: calib_config
  {
    out << "calib_config: ";
    rosidl_generator_traits::value_to_yaml(msg.calib_config, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CalibConfigRead_Response & msg,
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

  // member: error_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_message: ";
    rosidl_generator_traits::value_to_yaml(msg.error_message, out);
    out << "\n";
  }

  // member: calib_config
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "calib_config: ";
    rosidl_generator_traits::value_to_yaml(msg.calib_config, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CalibConfigRead_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace realsense2_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use realsense2_camera_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const realsense2_camera_msgs::srv::CalibConfigRead_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  realsense2_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use realsense2_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const realsense2_camera_msgs::srv::CalibConfigRead_Response & msg)
{
  return realsense2_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<realsense2_camera_msgs::srv::CalibConfigRead_Response>()
{
  return "realsense2_camera_msgs::srv::CalibConfigRead_Response";
}

template<>
inline const char * name<realsense2_camera_msgs::srv::CalibConfigRead_Response>()
{
  return "realsense2_camera_msgs/srv/CalibConfigRead_Response";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::srv::CalibConfigRead_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<realsense2_camera_msgs::srv::CalibConfigRead_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<realsense2_camera_msgs::srv::CalibConfigRead_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<realsense2_camera_msgs::srv::CalibConfigRead>()
{
  return "realsense2_camera_msgs::srv::CalibConfigRead";
}

template<>
inline const char * name<realsense2_camera_msgs::srv::CalibConfigRead>()
{
  return "realsense2_camera_msgs/srv/CalibConfigRead";
}

template<>
struct has_fixed_size<realsense2_camera_msgs::srv::CalibConfigRead>
  : std::integral_constant<
    bool,
    has_fixed_size<realsense2_camera_msgs::srv::CalibConfigRead_Request>::value &&
    has_fixed_size<realsense2_camera_msgs::srv::CalibConfigRead_Response>::value
  >
{
};

template<>
struct has_bounded_size<realsense2_camera_msgs::srv::CalibConfigRead>
  : std::integral_constant<
    bool,
    has_bounded_size<realsense2_camera_msgs::srv::CalibConfigRead_Request>::value &&
    has_bounded_size<realsense2_camera_msgs::srv::CalibConfigRead_Response>::value
  >
{
};

template<>
struct is_service<realsense2_camera_msgs::srv::CalibConfigRead>
  : std::true_type
{
};

template<>
struct is_service_request<realsense2_camera_msgs::srv::CalibConfigRead_Request>
  : std::true_type
{
};

template<>
struct is_service_response<realsense2_camera_msgs::srv::CalibConfigRead_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // REALSENSE2_CAMERA_MSGS__SRV__DETAIL__CALIB_CONFIG_READ__TRAITS_HPP_
