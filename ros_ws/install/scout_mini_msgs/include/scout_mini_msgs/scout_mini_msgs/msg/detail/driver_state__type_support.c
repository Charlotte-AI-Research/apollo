// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from scout_mini_msgs:msg/DriverState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "scout_mini_msgs/msg/detail/driver_state__rosidl_typesupport_introspection_c.h"
#include "scout_mini_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "scout_mini_msgs/msg/detail/driver_state__functions.h"
#include "scout_mini_msgs/msg/detail/driver_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  scout_mini_msgs__msg__DriverState__init(message_memory);
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_fini_function(void * message_memory)
{
  scout_mini_msgs__msg__DriverState__fini(message_memory);
}

size_t scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__driver_voltage(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_voltage(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_voltage(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__driver_voltage(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_voltage(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__driver_voltage(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_voltage(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__driver_temperature(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_temperature(
  const void * untyped_member, size_t index)
{
  const int16_t * member =
    (const int16_t *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_temperature(
  void * untyped_member, size_t index)
{
  int16_t * member =
    (int16_t *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__driver_temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_temperature(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__driver_temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_temperature(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

size_t scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__communication_failure(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__communication_failure(
  const void * untyped_member, size_t index)
{
  const bool * member =
    (const bool *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__communication_failure(
  void * untyped_member, size_t index)
{
  bool * member =
    (bool *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__communication_failure(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__communication_failure(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__communication_failure(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__communication_failure(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

size_t scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__low_supply_voltage(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__low_supply_voltage(
  const void * untyped_member, size_t index)
{
  const bool * member =
    (const bool *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__low_supply_voltage(
  void * untyped_member, size_t index)
{
  bool * member =
    (bool *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__low_supply_voltage(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__low_supply_voltage(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__low_supply_voltage(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__low_supply_voltage(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

size_t scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__motor_over_temperature(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__motor_over_temperature(
  const void * untyped_member, size_t index)
{
  const bool * member =
    (const bool *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__motor_over_temperature(
  void * untyped_member, size_t index)
{
  bool * member =
    (bool *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__motor_over_temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__motor_over_temperature(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__motor_over_temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__motor_over_temperature(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

size_t scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__driver_over_current(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_over_current(
  const void * untyped_member, size_t index)
{
  const bool * member =
    (const bool *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_over_current(
  void * untyped_member, size_t index)
{
  bool * member =
    (bool *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__driver_over_current(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_over_current(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__driver_over_current(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_over_current(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

size_t scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__driver_over_temperature(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_over_temperature(
  const void * untyped_member, size_t index)
{
  const bool * member =
    (const bool *)(untyped_member);
  return &member[index];
}

void * scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_over_temperature(
  void * untyped_member, size_t index)
{
  bool * member =
    (bool *)(untyped_member);
  return &member[index];
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__driver_over_temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_over_temperature(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__driver_over_temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_over_temperature(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__DriverState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "driver_voltage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__DriverState, driver_voltage),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__driver_voltage,  // size() function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_voltage,  // get_const(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_voltage,  // get(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__driver_voltage,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__driver_voltage,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "driver_temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__DriverState, driver_temperature),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__driver_temperature,  // size() function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_temperature,  // get_const(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_temperature,  // get(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__driver_temperature,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__driver_temperature,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "communication_failure",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__DriverState, communication_failure),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__communication_failure,  // size() function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__communication_failure,  // get_const(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__communication_failure,  // get(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__communication_failure,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__communication_failure,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "low_supply_voltage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__DriverState, low_supply_voltage),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__low_supply_voltage,  // size() function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__low_supply_voltage,  // get_const(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__low_supply_voltage,  // get(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__low_supply_voltage,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__low_supply_voltage,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motor_over_temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__DriverState, motor_over_temperature),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__motor_over_temperature,  // size() function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__motor_over_temperature,  // get_const(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__motor_over_temperature,  // get(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__motor_over_temperature,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__motor_over_temperature,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "driver_over_current",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__DriverState, driver_over_current),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__driver_over_current,  // size() function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_over_current,  // get_const(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_over_current,  // get(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__driver_over_current,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__driver_over_current,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "driver_over_temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(scout_mini_msgs__msg__DriverState, driver_over_temperature),  // bytes offset in struct
    NULL,  // default value
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__size_function__DriverState__driver_over_temperature,  // size() function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_const_function__DriverState__driver_over_temperature,  // get_const(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__get_function__DriverState__driver_over_temperature,  // get(index) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__fetch_function__DriverState__driver_over_temperature,  // fetch(index, &value) function pointer
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__assign_function__DriverState__driver_over_temperature,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_message_members = {
  "scout_mini_msgs__msg",  // message namespace
  "DriverState",  // message name
  8,  // number of fields
  sizeof(scout_mini_msgs__msg__DriverState),
  scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_message_member_array,  // message members
  scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_init_function,  // function to initialize message memory (memory has to be allocated)
  scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_message_type_support_handle = {
  0,
  &scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_scout_mini_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scout_mini_msgs, msg, DriverState)() {
  scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_message_type_support_handle.typesupport_identifier) {
    scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &scout_mini_msgs__msg__DriverState__rosidl_typesupport_introspection_c__DriverState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
