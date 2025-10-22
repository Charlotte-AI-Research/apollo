// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from scout_mini_msgs:msg/DriverState.idl
// generated code does not contain a copyright notice
#include "scout_mini_msgs/msg/detail/driver_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
scout_mini_msgs__msg__DriverState__init(scout_mini_msgs__msg__DriverState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    scout_mini_msgs__msg__DriverState__fini(msg);
    return false;
  }
  // driver_voltage
  // driver_temperature
  // communication_failure
  // low_supply_voltage
  // motor_over_temperature
  // driver_over_current
  // driver_over_temperature
  return true;
}

void
scout_mini_msgs__msg__DriverState__fini(scout_mini_msgs__msg__DriverState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // driver_voltage
  // driver_temperature
  // communication_failure
  // low_supply_voltage
  // motor_over_temperature
  // driver_over_current
  // driver_over_temperature
}

bool
scout_mini_msgs__msg__DriverState__are_equal(const scout_mini_msgs__msg__DriverState * lhs, const scout_mini_msgs__msg__DriverState * rhs)
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
  // driver_voltage
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->driver_voltage[i] != rhs->driver_voltage[i]) {
      return false;
    }
  }
  // driver_temperature
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->driver_temperature[i] != rhs->driver_temperature[i]) {
      return false;
    }
  }
  // communication_failure
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->communication_failure[i] != rhs->communication_failure[i]) {
      return false;
    }
  }
  // low_supply_voltage
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->low_supply_voltage[i] != rhs->low_supply_voltage[i]) {
      return false;
    }
  }
  // motor_over_temperature
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->motor_over_temperature[i] != rhs->motor_over_temperature[i]) {
      return false;
    }
  }
  // driver_over_current
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->driver_over_current[i] != rhs->driver_over_current[i]) {
      return false;
    }
  }
  // driver_over_temperature
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->driver_over_temperature[i] != rhs->driver_over_temperature[i]) {
      return false;
    }
  }
  return true;
}

bool
scout_mini_msgs__msg__DriverState__copy(
  const scout_mini_msgs__msg__DriverState * input,
  scout_mini_msgs__msg__DriverState * output)
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
  // driver_voltage
  for (size_t i = 0; i < 4; ++i) {
    output->driver_voltage[i] = input->driver_voltage[i];
  }
  // driver_temperature
  for (size_t i = 0; i < 4; ++i) {
    output->driver_temperature[i] = input->driver_temperature[i];
  }
  // communication_failure
  for (size_t i = 0; i < 4; ++i) {
    output->communication_failure[i] = input->communication_failure[i];
  }
  // low_supply_voltage
  for (size_t i = 0; i < 4; ++i) {
    output->low_supply_voltage[i] = input->low_supply_voltage[i];
  }
  // motor_over_temperature
  for (size_t i = 0; i < 4; ++i) {
    output->motor_over_temperature[i] = input->motor_over_temperature[i];
  }
  // driver_over_current
  for (size_t i = 0; i < 4; ++i) {
    output->driver_over_current[i] = input->driver_over_current[i];
  }
  // driver_over_temperature
  for (size_t i = 0; i < 4; ++i) {
    output->driver_over_temperature[i] = input->driver_over_temperature[i];
  }
  return true;
}

scout_mini_msgs__msg__DriverState *
scout_mini_msgs__msg__DriverState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__DriverState * msg = (scout_mini_msgs__msg__DriverState *)allocator.allocate(sizeof(scout_mini_msgs__msg__DriverState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scout_mini_msgs__msg__DriverState));
  bool success = scout_mini_msgs__msg__DriverState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scout_mini_msgs__msg__DriverState__destroy(scout_mini_msgs__msg__DriverState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scout_mini_msgs__msg__DriverState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scout_mini_msgs__msg__DriverState__Sequence__init(scout_mini_msgs__msg__DriverState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__DriverState * data = NULL;

  if (size) {
    data = (scout_mini_msgs__msg__DriverState *)allocator.zero_allocate(size, sizeof(scout_mini_msgs__msg__DriverState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scout_mini_msgs__msg__DriverState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scout_mini_msgs__msg__DriverState__fini(&data[i - 1]);
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
scout_mini_msgs__msg__DriverState__Sequence__fini(scout_mini_msgs__msg__DriverState__Sequence * array)
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
      scout_mini_msgs__msg__DriverState__fini(&array->data[i]);
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

scout_mini_msgs__msg__DriverState__Sequence *
scout_mini_msgs__msg__DriverState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__DriverState__Sequence * array = (scout_mini_msgs__msg__DriverState__Sequence *)allocator.allocate(sizeof(scout_mini_msgs__msg__DriverState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scout_mini_msgs__msg__DriverState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scout_mini_msgs__msg__DriverState__Sequence__destroy(scout_mini_msgs__msg__DriverState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scout_mini_msgs__msg__DriverState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scout_mini_msgs__msg__DriverState__Sequence__are_equal(const scout_mini_msgs__msg__DriverState__Sequence * lhs, const scout_mini_msgs__msg__DriverState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scout_mini_msgs__msg__DriverState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scout_mini_msgs__msg__DriverState__Sequence__copy(
  const scout_mini_msgs__msg__DriverState__Sequence * input,
  scout_mini_msgs__msg__DriverState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scout_mini_msgs__msg__DriverState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scout_mini_msgs__msg__DriverState * data =
      (scout_mini_msgs__msg__DriverState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scout_mini_msgs__msg__DriverState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scout_mini_msgs__msg__DriverState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scout_mini_msgs__msg__DriverState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
