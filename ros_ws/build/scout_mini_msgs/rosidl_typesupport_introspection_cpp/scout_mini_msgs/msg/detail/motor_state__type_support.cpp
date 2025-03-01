// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from scout_mini_msgs:msg/MotorState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "scout_mini_msgs/msg/detail/motor_state__struct.hpp"
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

void MotorState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) scout_mini_msgs::msg::MotorState(_init);
}

void MotorState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<scout_mini_msgs::msg::MotorState *>(message_memory);
  typed_message->~MotorState();
}

size_t size_function__MotorState__name(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__MotorState__name(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<std::string, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorState__name(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<std::string, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorState__name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__MotorState__name(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__MotorState__name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__MotorState__name(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

size_t size_function__MotorState__position(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__MotorState__position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorState__position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorState__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__MotorState__position(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__MotorState__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__MotorState__position(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__MotorState__velocity(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__MotorState__velocity(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorState__velocity(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorState__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__MotorState__velocity(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__MotorState__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__MotorState__velocity(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__MotorState__current(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__MotorState__current(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorState__current(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorState__current(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__MotorState__current(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__MotorState__current(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__MotorState__current(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__MotorState__temperature(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__MotorState__temperature(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int16_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorState__temperature(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int16_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorState__temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__MotorState__temperature(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__MotorState__temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__MotorState__temperature(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotorState_message_member_array[6] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::MotorState, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::MotorState, name),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorState__name,  // size() function pointer
    get_const_function__MotorState__name,  // get_const(index) function pointer
    get_function__MotorState__name,  // get(index) function pointer
    fetch_function__MotorState__name,  // fetch(index, &value) function pointer
    assign_function__MotorState__name,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::MotorState, position),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorState__position,  // size() function pointer
    get_const_function__MotorState__position,  // get_const(index) function pointer
    get_function__MotorState__position,  // get(index) function pointer
    fetch_function__MotorState__position,  // fetch(index, &value) function pointer
    assign_function__MotorState__position,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::MotorState, velocity),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorState__velocity,  // size() function pointer
    get_const_function__MotorState__velocity,  // get_const(index) function pointer
    get_function__MotorState__velocity,  // get(index) function pointer
    fetch_function__MotorState__velocity,  // fetch(index, &value) function pointer
    assign_function__MotorState__velocity,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "current",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::MotorState, current),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorState__current,  // size() function pointer
    get_const_function__MotorState__current,  // get_const(index) function pointer
    get_function__MotorState__current,  // get(index) function pointer
    fetch_function__MotorState__current,  // fetch(index, &value) function pointer
    assign_function__MotorState__current,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "temperature",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::MotorState, temperature),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorState__temperature,  // size() function pointer
    get_const_function__MotorState__temperature,  // get_const(index) function pointer
    get_function__MotorState__temperature,  // get(index) function pointer
    fetch_function__MotorState__temperature,  // fetch(index, &value) function pointer
    assign_function__MotorState__temperature,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotorState_message_members = {
  "scout_mini_msgs::msg",  // message namespace
  "MotorState",  // message name
  6,  // number of fields
  sizeof(scout_mini_msgs::msg::MotorState),
  MotorState_message_member_array,  // message members
  MotorState_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotorState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotorState_message_members,
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
get_message_type_support_handle<scout_mini_msgs::msg::MotorState>()
{
  return &::scout_mini_msgs::msg::rosidl_typesupport_introspection_cpp::MotorState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, scout_mini_msgs, msg, MotorState)() {
  return &::scout_mini_msgs::msg::rosidl_typesupport_introspection_cpp::MotorState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
