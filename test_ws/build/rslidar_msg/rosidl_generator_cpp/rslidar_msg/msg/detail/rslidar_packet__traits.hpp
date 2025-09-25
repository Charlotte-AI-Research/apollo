// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rslidar_msg:msg/RslidarPacket.idl
// generated code does not contain a copyright notice

#ifndef RSLIDAR_MSG__MSG__DETAIL__RSLIDAR_PACKET__TRAITS_HPP_
#define RSLIDAR_MSG__MSG__DETAIL__RSLIDAR_PACKET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rslidar_msg/msg/detail/rslidar_packet__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rslidar_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const RslidarPacket & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: is_difop
  {
    out << "is_difop: ";
    rosidl_generator_traits::value_to_yaml(msg.is_difop, out);
    out << ", ";
  }

  // member: is_frame_begin
  {
    out << "is_frame_begin: ";
    rosidl_generator_traits::value_to_yaml(msg.is_frame_begin, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RslidarPacket & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: is_difop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_difop: ";
    rosidl_generator_traits::value_to_yaml(msg.is_difop, out);
    out << "\n";
  }

  // member: is_frame_begin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_frame_begin: ";
    rosidl_generator_traits::value_to_yaml(msg.is_frame_begin, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RslidarPacket & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rslidar_msg

namespace rosidl_generator_traits
{

[[deprecated("use rslidar_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rslidar_msg::msg::RslidarPacket & msg,
  std::ostream & out, size_t indentation = 0)
{
  rslidar_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rslidar_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const rslidar_msg::msg::RslidarPacket & msg)
{
  return rslidar_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rslidar_msg::msg::RslidarPacket>()
{
  return "rslidar_msg::msg::RslidarPacket";
}

template<>
inline const char * name<rslidar_msg::msg::RslidarPacket>()
{
  return "rslidar_msg/msg/RslidarPacket";
}

template<>
struct has_fixed_size<rslidar_msg::msg::RslidarPacket>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rslidar_msg::msg::RslidarPacket>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rslidar_msg::msg::RslidarPacket>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RSLIDAR_MSG__MSG__DETAIL__RSLIDAR_PACKET__TRAITS_HPP_
