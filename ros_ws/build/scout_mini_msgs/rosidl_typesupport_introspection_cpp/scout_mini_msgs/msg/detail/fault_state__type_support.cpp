// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from scout_mini_msgs:msg/FaultState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "scout_mini_msgs/msg/detail/fault_state__struct.hpp"
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

void FaultState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) scout_mini_msgs::msg::FaultState(_init);
}

void FaultState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<scout_mini_msgs::msg::FaultState *>(message_memory);
  typed_message->~FaultState();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FaultState_message_member_array[3] = {
  {
    "battery_under_voltage_failure",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::FaultState, battery_under_voltage_failure),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "battery_under_voltage_alarm",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::FaultState, battery_under_voltage_alarm),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "loss_remote_control",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs::msg::FaultState, loss_remote_control),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FaultState_message_members = {
  "scout_mini_msgs::msg",  // message namespace
  "FaultState",  // message name
  3,  // number of fields
  sizeof(scout_mini_msgs::msg::FaultState),
  FaultState_message_member_array,  // message members
  FaultState_init_function,  // function to initialize message memory (memory has to be allocated)
  FaultState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FaultState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FaultState_message_members,
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
get_message_type_support_handle<scout_mini_msgs::msg::FaultState>()
{
  return &::scout_mini_msgs::msg::rosidl_typesupport_introspection_cpp::FaultState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, scout_mini_msgs, msg, FaultState)() {
  return &::scout_mini_msgs::msg::rosidl_typesupport_introspection_cpp::FaultState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
