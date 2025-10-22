// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from scout_mini_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice
#include "scout_mini_msgs/msg/detail/robot_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `robot`
// Member `control_mode`
#include "rosidl_runtime_c/string_functions.h"
// Member `fault_state`
#include "scout_mini_msgs/msg/detail/fault_state__functions.h"

bool
scout_mini_msgs__msg__RobotState__init(scout_mini_msgs__msg__RobotState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    scout_mini_msgs__msg__RobotState__fini(msg);
    return false;
  }
  // robot
  if (!rosidl_runtime_c__String__init(&msg->robot)) {
    scout_mini_msgs__msg__RobotState__fini(msg);
    return false;
  }
  // normal_state
  // control_mode
  if (!rosidl_runtime_c__String__init(&msg->control_mode)) {
    scout_mini_msgs__msg__RobotState__fini(msg);
    return false;
  }
  // battery_voltage
  // fault_state
  if (!scout_mini_msgs__msg__FaultState__init(&msg->fault_state)) {
    scout_mini_msgs__msg__RobotState__fini(msg);
    return false;
  }
  return true;
}

void
scout_mini_msgs__msg__RobotState__fini(scout_mini_msgs__msg__RobotState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // robot
  rosidl_runtime_c__String__fini(&msg->robot);
  // normal_state
  // control_mode
  rosidl_runtime_c__String__fini(&msg->control_mode);
  // battery_voltage
  // fault_state
  scout_mini_msgs__msg__FaultState__fini(&msg->fault_state);
}

bool
scout_mini_msgs__msg__RobotState__are_equal(const scout_mini_msgs__msg__RobotState * lhs, const scout_mini_msgs__msg__RobotState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // robot
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot), &(rhs->robot)))
  {
    return false;
  }
  // normal_state
  if (lhs->normal_state != rhs->normal_state) {
    return false;
  }
  // control_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->control_mode), &(rhs->control_mode)))
  {
    return false;
  }
  // battery_voltage
  if (lhs->battery_voltage != rhs->battery_voltage) {
    return false;
  }
  // fault_state
  if (!scout_mini_msgs__msg__FaultState__are_equal(
      &(lhs->fault_state), &(rhs->fault_state)))
  {
    return false;
  }
  return true;
}

bool
scout_mini_msgs__msg__RobotState__copy(
  const scout_mini_msgs__msg__RobotState * input,
  scout_mini_msgs__msg__RobotState * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // robot
  if (!rosidl_runtime_c__String__copy(
      &(input->robot), &(output->robot)))
  {
    return false;
  }
  // normal_state
  output->normal_state = input->normal_state;
  // control_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->control_mode), &(output->control_mode)))
  {
    return false;
  }
  // battery_voltage
  output->battery_voltage = input->battery_voltage;
  // fault_state
  if (!scout_mini_msgs__msg__FaultState__copy(
      &(input->fault_state), &(output->fault_state)))
  {
    return false;
  }
  return true;
}

scout_mini_msgs__msg__RobotState *
scout_mini_msgs__msg__RobotState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__RobotState * msg = (scout_mini_msgs__msg__RobotState *)allocator.allocate(sizeof(scout_mini_msgs__msg__RobotState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scout_mini_msgs__msg__RobotState));
  bool success = scout_mini_msgs__msg__RobotState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scout_mini_msgs__msg__RobotState__destroy(scout_mini_msgs__msg__RobotState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scout_mini_msgs__msg__RobotState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scout_mini_msgs__msg__RobotState__Sequence__init(scout_mini_msgs__msg__RobotState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__RobotState * data = NULL;

  if (size) {
    data = (scout_mini_msgs__msg__RobotState *)allocator.zero_allocate(size, sizeof(scout_mini_msgs__msg__RobotState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scout_mini_msgs__msg__RobotState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scout_mini_msgs__msg__RobotState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
scout_mini_msgs__msg__RobotState__Sequence__fini(scout_mini_msgs__msg__RobotState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      scout_mini_msgs__msg__RobotState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

scout_mini_msgs__msg__RobotState__Sequence *
scout_mini_msgs__msg__RobotState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__RobotState__Sequence * array = (scout_mini_msgs__msg__RobotState__Sequence *)allocator.allocate(sizeof(scout_mini_msgs__msg__RobotState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scout_mini_msgs__msg__RobotState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scout_mini_msgs__msg__RobotState__Sequence__destroy(scout_mini_msgs__msg__RobotState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scout_mini_msgs__msg__RobotState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scout_mini_msgs__msg__RobotState__Sequence__are_equal(const scout_mini_msgs__msg__RobotState__Sequence * lhs, const scout_mini_msgs__msg__RobotState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scout_mini_msgs__msg__RobotState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scout_mini_msgs__msg__RobotState__Sequence__copy(
  const scout_mini_msgs__msg__RobotState__Sequence * input,
  scout_mini_msgs__msg__RobotState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scout_mini_msgs__msg__RobotState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scout_mini_msgs__msg__RobotState * data =
      (scout_mini_msgs__msg__RobotState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scout_mini_msgs__msg__RobotState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scout_mini_msgs__msg__RobotState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scout_mini_msgs__msg__RobotState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
