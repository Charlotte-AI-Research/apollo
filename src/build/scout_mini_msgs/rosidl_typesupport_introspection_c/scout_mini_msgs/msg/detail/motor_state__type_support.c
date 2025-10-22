// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from scout_mini_msgs:msg/MotorState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "scout_mini_msgs/msg/detail/motor_state__rosidl_typesupport_introspection_c.h"
#include "scout_mini_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "scout_mini_msgs/msg/detail/motor_state__functions.h"
#include "scout_mini_msgs/msg/detail/motor_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  scout_mini_msgs__msg__MotorState__init(message_memory);
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_fini_function(void * message_memory)
{
  scout_mini_msgs__msg__MotorState__fini(message_memory);
}

size_t scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__name(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__name(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String * member =
    (const rosidl_runtime_c__String *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__name(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String * member =
    (rosidl_runtime_c__String *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__name(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__name(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

size_t scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__position(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__position(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__position(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__position(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__position(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__velocity(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__velocity(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__velocity(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__velocity(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__velocity(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__current(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__current(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__current(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__current(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__current(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__current(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__current(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__temperature(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__temperature(
  const void * untyped_member, size_t index)
{
  const int16_t * member =
    (const int16_t *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__temperature(
  void * untyped_member, size_t index)
{
  int16_t * member =
    (int16_t *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__temperature(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__temperature(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__MotorState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__MotorState, name),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__name,  // size() function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__name,  // get_const(index) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__name,  // get(index) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__name,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__name,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__MotorState, position),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__position,  // size() function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__position,  // get_const(index) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__position,  // get(index) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__position,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__position,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__MotorState, velocity),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__velocity,  // size() function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__velocity,  // get_const(index) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__velocity,  // get(index) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__velocity,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__velocity,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__MotorState, current),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__current,  // size() function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__current,  // get_const(index) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__current,  // get(index) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__current,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__current,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__MotorState, temperature),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__size_function__MotorState__temperature,  // size() function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_const_function__MotorState__temperature,  // get_const(index) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__get_function__MotorState__temperature,  // get(index) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__fetch_function__MotorState__temperature,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__assign_function__MotorState__temperature,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_members = {
  "scout_mini_msgs__msg",  // message namespace
  "MotorState",  // message name
  6,  // number of fields
  sizeof(scout_mini_msgs__msg__MotorState),
  scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_member_array,  // message members
  scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_init_function,  // function to initialize message memory (memory has to be allocated)
  scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_type_support_handle = {
  0,
  &scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_scout_mini_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scout_mini_msgs, msg, MotorState)() {
  scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_type_support_handle.typesupport_identifier) {
    scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &scout_mini_msgs__msg__MotorState__rosidl_typesupport_introspection_c__MotorState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
