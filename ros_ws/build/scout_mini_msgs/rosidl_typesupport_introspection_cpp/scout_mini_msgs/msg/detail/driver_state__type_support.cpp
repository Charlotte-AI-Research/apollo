// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from scout_mini_msgs:msg/DriverState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "scout_mini_msgs/msg/detail/driver_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace scout_mini_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DriverState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) scout_mini_msgs::msg::DriverState(_init);
}

void DriverState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<scout_mini_msgs::msg::DriverState *>(message_memory);
  typed_message->~DriverState();
}

size_t size_function__DriverState__driver_voltage(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__DriverState__driver_voltage(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__DriverState__driver_voltage(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__DriverState__driver_voltage(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__DriverState__driver_voltage(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__DriverState__driver_voltage(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__DriverState__driver_voltage(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__DriverState__driver_temperature(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__DriverState__driver_temperature(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int16_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__DriverState__driver_temperature(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int16_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__DriverState__driver_temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__DriverState__driver_temperature(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__DriverState__driver_temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__DriverState__driver_temperature(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

size_t size_function__DriverState__communication_failure(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__DriverState__communication_failure(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__DriverState__communication_failure(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__DriverState__communication_failure(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__DriverState__communication_failure(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__DriverState__communication_failure(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__DriverState__communication_failure(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__DriverState__low_supply_voltage(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__DriverState__low_supply_voltage(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__DriverState__low_supply_voltage(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__DriverState__low_supply_voltage(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__DriverState__low_supply_voltage(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__DriverState__low_supply_voltage(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__DriverState__low_supply_voltage(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__DriverState__motor_over_temperature(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__DriverState__motor_over_temperature(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__DriverState__motor_over_temperature(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__DriverState__motor_over_temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__DriverState__motor_over_temperature(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__DriverState__motor_over_temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__DriverState__motor_over_temperature(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__DriverState__driver_over_current(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__DriverState__driver_over_current(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__DriverState__driver_over_current(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__DriverState__driver_over_current(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__DriverState__driver_over_current(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__DriverState__driver_over_current(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__DriverState__driver_over_current(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__DriverState__driver_over_temperature(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__DriverState__driver_over_temperature(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__DriverState__driver_over_temperature(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__DriverState__driver_over_temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__DriverState__driver_over_temperature(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__DriverState__driver_over_temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__DriverState__driver_over_temperature(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DriverState_message_member_array[8] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::DriverState, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "driver_voltage",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::DriverState, driver_voltage),  // bytes offset in struct
    nullptr,  // default value
    size_function__DriverState__driver_voltage,  // size() function pointer
    get_const_function__DriverState__driver_voltage,  // get_const(index) function pointer
    get_function__DriverState__driver_voltage,  // get(index) function pointer
    fetch_function__DriverState__driver_voltage,  // fetch(index, &value) function pointer
    assign_function__DriverState__driver_voltage,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "driver_temperature",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::DriverState, driver_temperature),  // bytes offset in struct
    nullptr,  // default value
    size_function__DriverState__driver_temperature,  // size() function pointer
    get_const_function__DriverState__driver_temperature,  // get_const(index) function pointer
    get_function__DriverState__driver_temperature,  // get(index) function pointer
    fetch_function__DriverState__driver_temperature,  // fetch(index, &value) function pointer
    assign_function__DriverState__driver_temperature,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "communication_failure",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::DriverState, communication_failure),  // bytes offset in struct
    nullptr,  // default value
    size_function__DriverState__communication_failure,  // size() function pointer
    get_const_function__DriverState__communication_failure,  // get_const(index) function pointer
    get_function__DriverState__communication_failure,  // get(index) function pointer
    fetch_function__DriverState__communication_failure,  // fetch(index, &value) function pointer
    assign_function__DriverState__communication_failure,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "low_supply_voltage",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::DriverState, low_supply_voltage),  // bytes offset in struct
    nullptr,  // default value
    size_function__DriverState__low_supply_voltage,  // size() function pointer
    get_const_function__DriverState__low_supply_voltage,  // get_const(index) function pointer
    get_function__DriverState__low_supply_voltage,  // get(index) function pointer
    fetch_function__DriverState__low_supply_voltage,  // fetch(index, &value) function pointer
    assign_function__DriverState__low_supply_voltage,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "motor_over_temperature",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::DriverState, motor_over_temperature),  // bytes offset in struct
    nullptr,  // default value
    size_function__DriverState__motor_over_temperature,  // size() function pointer
    get_const_function__DriverState__motor_over_temperature,  // get_const(index) function pointer
    get_function__DriverState__motor_over_temperature,  // get(index) function pointer
    fetch_function__DriverState__motor_over_temperature,  // fetch(index, &value) function pointer
    assign_function__DriverState__motor_over_temperature,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "driver_over_current",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::DriverState, driver_over_current),  // bytes offset in struct
    nullptr,  // default value
    size_function__DriverState__driver_over_current,  // size() function pointer
    get_const_function__DriverState__driver_over_current,  // get_const(index) function pointer
    get_function__DriverState__driver_over_current,  // get(index) function pointer
    fetch_function__DriverState__driver_over_current,  // fetch(index, &value) function pointer
    assign_function__DriverState__driver_over_current,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "driver_over_temperature",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::DriverState, driver_over_temperature),  // bytes offset in struct
    nullptr,  // default value
    size_function__DriverState__driver_over_temperature,  // size() function pointer
    get_const_function__DriverState__driver_over_temperature,  // get_const(index) function pointer
    get_function__DriverState__driver_over_temperature,  // get(index) function pointer
    fetch_function__DriverState__driver_over_temperature,  // fetch(index, &value) function pointer
    assign_function__DriverState__driver_over_temperature,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DriverState_message_members = {
  "scout_mini_msgs::msg",  // message namespace
  "DriverState",  // message name
  8,  // number of fields
  sizeof(scout_mini_msgs::msg::DriverState),
  DriverState_message_member_array,  // message members
  DriverState_init_function,  // function to initialize message memory (memory has to be allocated)
  DriverState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DriverState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DriverState_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace scout_mini_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<scout_mini_msgs::msg::DriverState>()
{
  return &::scout_mini_msgs::msg::rosidl_typesupport_introspection_cpp::DriverState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, scout_mini_msgs, msg, DriverState)() {
  return &::scout_mini_msgs::msg::rosidl_typesupport_introspection_cpp::DriverState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
