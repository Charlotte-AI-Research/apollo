// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from scout_mini_msgs:msg/MotorState.idl
// generated code does not contain a copyright notice
#include "scout_mini_msgs/msg/detail/motor_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
scout_mini_msgs__msg__MotorState__init(scout_mini_msgs__msg__MotorState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    scout_mini_msgs__msg__MotorState__fini(msg);
    return false;
  }
  // name
  for (size_t i = 0; i < 4; ++i) {
    if (!rosidl_runtime_c__String__init(&msg->name[i])) {
      scout_mini_msgs__msg__MotorState__fini(msg);
      return false;
    }
  }
  // position
  // velocity
  // current
  // temperature
  return true;
}

void
scout_mini_msgs__msg__MotorState__fini(scout_mini_msgs__msg__MotorState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // name
  for (size_t i = 0; i < 4; ++i) {
    rosidl_runtime_c__String__fini(&msg->name[i]);
  }
  // position
  // velocity
  // current
  // temperature
}

bool
scout_mini_msgs__msg__MotorState__are_equal(const scout_mini_msgs__msg__MotorState * lhs, const scout_mini_msgs__msg__MotorState * rhs)
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
  // name
  for (size_t i = 0; i < 4; ++i) {
    if (!rosidl_runtime_c__String__are_equal(
        &(lhs->name[i]), &(rhs->name[i])))
    {
      return false;
    }
  }
  // position
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->position[i] != rhs->position[i]) {
      return false;
    }
  }
  // velocity
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->velocity[i] != rhs->velocity[i]) {
      return false;
    }
  }
  // current
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->current[i] != rhs->current[i]) {
      return false;
    }
  }
  // temperature
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->temperature[i] != rhs->temperature[i]) {
      return false;
    }
  }
  return true;
}

bool
scout_mini_msgs__msg__MotorState__copy(
  const scout_mini_msgs__msg__MotorState * input,
  scout_mini_msgs__msg__MotorState * output)
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
  // name
  for (size_t i = 0; i < 4; ++i) {
    if (!rosidl_runtime_c__String__copy(
        &(input->name[i]), &(output->name[i])))
    {
      return false;
    }
  }
  // position
  for (size_t i = 0; i < 4; ++i) {
    output->position[i] = input->position[i];
  }
  // velocity
  for (size_t i = 0; i < 4; ++i) {
    output->velocity[i] = input->velocity[i];
  }
  // current
  for (size_t i = 0; i < 4; ++i) {
    output->current[i] = input->current[i];
  }
  // temperature
  for (size_t i = 0; i < 4; ++i) {
    output->temperature[i] = input->temperature[i];
  }
  return true;
}

scout_mini_msgs__msg__MotorState *
scout_mini_msgs__msg__MotorState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__MotorState * msg = (scout_mini_msgs__msg__MotorState *)allocator.allocate(sizeof(scout_mini_msgs__msg__MotorState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scout_mini_msgs__msg__MotorState));
  bool success = scout_mini_msgs__msg__MotorState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scout_mini_msgs__msg__MotorState__destroy(scout_mini_msgs__msg__MotorState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scout_mini_msgs__msg__MotorState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scout_mini_msgs__msg__MotorState__Sequence__init(scout_mini_msgs__msg__MotorState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__MotorState * data = NULL;

  if (size) {
    data = (scout_mini_msgs__msg__MotorState *)allocator.zero_allocate(size, sizeof(scout_mini_msgs__msg__MotorState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scout_mini_msgs__msg__MotorState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scout_mini_msgs__msg__MotorState__fini(&data[i - 1]);
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
scout_mini_msgs__msg__MotorState__Sequence__fini(scout_mini_msgs__msg__MotorState__Sequence * array)
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
      scout_mini_msgs__msg__MotorState__fini(&array->data[i]);
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

scout_mini_msgs__msg__MotorState__Sequence *
scout_mini_msgs__msg__MotorState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__MotorState__Sequence * array = (scout_mini_msgs__msg__MotorState__Sequence *)allocator.allocate(sizeof(scout_mini_msgs__msg__MotorState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scout_mini_msgs__msg__MotorState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scout_mini_msgs__msg__MotorState__Sequence__destroy(scout_mini_msgs__msg__MotorState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scout_mini_msgs__msg__MotorState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scout_mini_msgs__msg__MotorState__Sequence__are_equal(const scout_mini_msgs__msg__MotorState__Sequence * lhs, const scout_mini_msgs__msg__MotorState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scout_mini_msgs__msg__MotorState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scout_mini_msgs__msg__MotorState__Sequence__copy(
  const scout_mini_msgs__msg__MotorState__Sequence * input,
  scout_mini_msgs__msg__MotorState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scout_mini_msgs__msg__MotorState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scout_mini_msgs__msg__MotorState * data =
      (scout_mini_msgs__msg__MotorState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scout_mini_msgs__msg__MotorState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scout_mini_msgs__msg__MotorState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scout_mini_msgs__msg__MotorState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
