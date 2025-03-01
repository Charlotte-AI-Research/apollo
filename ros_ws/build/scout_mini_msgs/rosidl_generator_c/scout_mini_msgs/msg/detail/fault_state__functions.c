// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from scout_mini_msgs:msg/FaultState.idl
// generated code does not contain a copyright notice
#include "scout_mini_msgs/msg/detail/fault_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
scout_mini_msgs__msg__FaultState__init(scout_mini_msgs__msg__FaultState * msg)
{
  if (!msg) {
    return false;
  }
  // battery_under_voltage_failure
  // battery_under_voltage_alarm
  // loss_remote_control
  return true;
}

void
scout_mini_msgs__msg__FaultState__fini(scout_mini_msgs__msg__FaultState * msg)
{
  if (!msg) {
    return;
  }
  // battery_under_voltage_failure
  // battery_under_voltage_alarm
  // loss_remote_control
}

bool
scout_mini_msgs__msg__FaultState__are_equal(const scout_mini_msgs__msg__FaultState * lhs, const scout_mini_msgs__msg__FaultState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // battery_under_voltage_failure
  if (lhs->battery_under_voltage_failure != rhs->battery_under_voltage_failure) {
    return false;
  }
  // battery_under_voltage_alarm
  if (lhs->battery_under_voltage_alarm != rhs->battery_under_voltage_alarm) {
    return false;
  }
  // loss_remote_control
  if (lhs->loss_remote_control != rhs->loss_remote_control) {
    return false;
  }
  return true;
}

bool
scout_mini_msgs__msg__FaultState__copy(
  const scout_mini_msgs__msg__FaultState * input,
  scout_mini_msgs__msg__FaultState * output)
{
  if (!input || !output) {
    return false;
  }
  // battery_under_voltage_failure
  output->battery_under_voltage_failure = input->battery_under_voltage_failure;
  // battery_under_voltage_alarm
  output->battery_under_voltage_alarm = input->battery_under_voltage_alarm;
  // loss_remote_control
  output->loss_remote_control = input->loss_remote_control;
  return true;
}

scout_mini_msgs__msg__FaultState *
scout_mini_msgs__msg__FaultState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__FaultState * msg = (scout_mini_msgs__msg__FaultState *)allocator.allocate(sizeof(scout_mini_msgs__msg__FaultState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scout_mini_msgs__msg__FaultState));
  bool success = scout_mini_msgs__msg__FaultState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scout_mini_msgs__msg__FaultState__destroy(scout_mini_msgs__msg__FaultState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scout_mini_msgs__msg__FaultState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scout_mini_msgs__msg__FaultState__Sequence__init(scout_mini_msgs__msg__FaultState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__FaultState * data = NULL;

  if (size) {
    data = (scout_mini_msgs__msg__FaultState *)allocator.zero_allocate(size, sizeof(scout_mini_msgs__msg__FaultState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scout_mini_msgs__msg__FaultState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scout_mini_msgs__msg__FaultState__fini(&data[i - 1]);
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
scout_mini_msgs__msg__FaultState__Sequence__fini(scout_mini_msgs__msg__FaultState__Sequence * array)
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
      scout_mini_msgs__msg__FaultState__fini(&array->data[i]);
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

scout_mini_msgs__msg__FaultState__Sequence *
scout_mini_msgs__msg__FaultState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__FaultState__Sequence * array = (scout_mini_msgs__msg__FaultState__Sequence *)allocator.allocate(sizeof(scout_mini_msgs__msg__FaultState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scout_mini_msgs__msg__FaultState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scout_mini_msgs__msg__FaultState__Sequence__destroy(scout_mini_msgs__msg__FaultState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scout_mini_msgs__msg__FaultState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scout_mini_msgs__msg__FaultState__Sequence__are_equal(const scout_mini_msgs__msg__FaultState__Sequence * lhs, const scout_mini_msgs__msg__FaultState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scout_mini_msgs__msg__FaultState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scout_mini_msgs__msg__FaultState__Sequence__copy(
  const scout_mini_msgs__msg__FaultState__Sequence * input,
  scout_mini_msgs__msg__FaultState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scout_mini_msgs__msg__FaultState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scout_mini_msgs__msg__FaultState * data =
      (scout_mini_msgs__msg__FaultState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scout_mini_msgs__msg__FaultState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scout_mini_msgs__msg__FaultState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scout_mini_msgs__msg__FaultState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
