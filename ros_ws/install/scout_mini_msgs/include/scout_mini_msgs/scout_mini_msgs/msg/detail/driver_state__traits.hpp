// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from scout_mini_msgs:msg/DriverState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__TRAITS_HPP_
#define SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "scout_mini_msgs/msg/detail/driver_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace scout_mini_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DriverState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: driver_voltage
  {
    if (msg.driver_voltage.size() == 0) {
      out << "driver_voltage: []";
    } else {
      out << "driver_voltage: [";
      size_t pending_items = msg.driver_voltage.size();
      for (auto item : msg.driver_voltage) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: driver_temperature
  {
    if (msg.driver_temperature.size() == 0) {
      out << "driver_temperature: []";
    } else {
      out << "driver_temperature: [";
      size_t pending_items = msg.driver_temperature.size();
      for (auto item : msg.driver_temperature) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: communication_failure
  {
    if (msg.communication_failure.size() == 0) {
      out << "communication_failure: []";
    } else {
      out << "communication_failure: [";
      size_t pending_items = msg.communication_failure.size();
      for (auto item : msg.communication_failure) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: low_supply_voltage
  {
    if (msg.low_supply_voltage.size() == 0) {
      out << "low_supply_voltage: []";
    } else {
      out << "low_supply_voltage: [";
      size_t pending_items = msg.low_supply_voltage.size();
      for (auto item : msg.low_supply_voltage) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: motor_over_temperature
  {
    if (msg.motor_over_temperature.size() == 0) {
      out << "motor_over_temperature: []";
    } else {
      out << "motor_over_temperature: [";
      size_t pending_items = msg.motor_over_temperature.size();
      for (auto item : msg.motor_over_temperature) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: driver_over_current
  {
    if (msg.driver_over_current.size() == 0) {
      out << "driver_over_current: []";
    } else {
      out << "driver_over_current: [";
      size_t pending_items = msg.driver_over_current.size();
      for (auto item : msg.driver_over_current) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: driver_over_temperature
  {
    if (msg.driver_over_temperature.size() == 0) {
      out << "driver_over_temperature: []";
    } else {
      out << "driver_over_temperature: [";
      size_t pending_items = msg.driver_over_temperature.size();
      for (auto item : msg.driver_over_temperature) {
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
  const DriverState & msg,
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

  // member: driver_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.driver_voltage.size() == 0) {
      out << "driver_voltage: []\n";
    } else {
      out << "driver_voltage:\n";
      for (auto item : msg.driver_voltage) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: driver_temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.driver_temperature.size() == 0) {
      out << "driver_temperature: []\n";
    } else {
      out << "driver_temperature:\n";
      for (auto item : msg.driver_temperature) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: communication_failure
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.communication_failure.size() == 0) {
      out << "communication_failure: []\n";
    } else {
      out << "communication_failure:\n";
      for (auto item : msg.communication_failure) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: low_supply_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.low_supply_voltage.size() == 0) {
      out << "low_supply_voltage: []\n";
    } else {
      out << "low_supply_voltage:\n";
      for (auto item : msg.low_supply_voltage) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: motor_over_temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_over_temperature.size() == 0) {
      out << "motor_over_temperature: []\n";
    } else {
      out << "motor_over_temperature:\n";
      for (auto item : msg.motor_over_temperature) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: driver_over_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.driver_over_current.size() == 0) {
      out << "driver_over_current: []\n";
    } else {
      out << "driver_over_current:\n";
      for (auto item : msg.driver_over_current) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: driver_over_temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.driver_over_temperature.size() == 0) {
      out << "driver_over_temperature: []\n";
    } else {
      out << "driver_over_temperature:\n";
      for (auto item : msg.driver_over_temperature) {
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

inline std::string to_yaml(const DriverState & msg, bool use_flow_style = false)
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

}  // namespace scout_mini_msgs

namespace rosidl_generator_traits
{

[[deprecated("use scout_mini_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const scout_mini_msgs::msg::DriverState & msg,
  std::ostream & out, size_t indentation = 0)
{
  scout_mini_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use scout_mini_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const scout_mini_msgs::msg::DriverState & msg)
{
  return scout_mini_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<scout_mini_msgs::msg::DriverState>()
{
  return "scout_mini_msgs::msg::DriverState";
}

template<>
inline const char * name<scout_mini_msgs::msg::DriverState>()
{
  return "scout_mini_msgs/msg/DriverState";
}

template<>
struct has_fixed_size<scout_mini_msgs::msg::DriverState>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<scout_mini_msgs::msg::DriverState>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<scout_mini_msgs::msg::DriverState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__DRIVER_STATE__TRAITS_HPP_
