// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from scout_mini_msgs:msg/LightState.idl
// generated code does not contain a copyright notice
#include "scout_mini_msgs/msg/detail/light_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"

bool
scout_mini_msgs__msg__LightState__init(scout_mini_msgs__msg__LightState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    scout_mini_msgs__msg__LightState__fini(msg);
    return false;
  }
  // control_enable
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    scout_mini_msgs__msg__LightState__fini(msg);
    return false;
  }
  // brightness
  return true;
}

void
scout_mini_msgs__msg__LightState__fini(scout_mini_msgs__msg__LightState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // control_enable
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
  // brightness
}

bool
scout_mini_msgs__msg__LightState__are_equal(const scout_mini_msgs__msg__LightState * lhs, const scout_mini_msgs__msg__LightState * rhs)
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
  // control_enable
  if (lhs->control_enable != rhs->control_enable) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  // brightness
  if (lhs->brightness != rhs->brightness) {
    return false;
  }
  return true;
}

bool
scout_mini_msgs__msg__LightState__copy(
  const scout_mini_msgs__msg__LightState * input,
  scout_mini_msgs__msg__LightState * output)
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
  // control_enable
  output->control_enable = input->control_enable;
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  // brightness
  output->brightness = input->brightness;
  return true;
}

scout_mini_msgs__msg__LightState *
scout_mini_msgs__msg__LightState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__LightState * msg = (scout_mini_msgs__msg__LightState *)allocator.allocate(sizeof(scout_mini_msgs__msg__LightState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scout_mini_msgs__msg__LightState));
  bool success = scout_mini_msgs__msg__LightState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scout_mini_msgs__msg__LightState__destroy(scout_mini_msgs__msg__LightState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scout_mini_msgs__msg__LightState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scout_mini_msgs__msg__LightState__Sequence__init(scout_mini_msgs__msg__LightState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__LightState * data = NULL;

  if (size) {
    data = (scout_mini_msgs__msg__LightState *)allocator.zero_allocate(size, sizeof(scout_mini_msgs__msg__LightState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scout_mini_msgs__msg__LightState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scout_mini_msgs__msg__LightState__fini(&data[i - 1]);
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
scout_mini_msgs__msg__LightState__Sequence__fini(scout_mini_msgs__msg__LightState__Sequence * array)
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
      scout_mini_msgs__msg__LightState__fini(&array->data[i]);
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

scout_mini_msgs__msg__LightState__Sequence *
scout_mini_msgs__msg__LightState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__LightState__Sequence * array = (scout_mini_msgs__msg__LightState__Sequence *)allocator.allocate(sizeof(scout_mini_msgs__msg__LightState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scout_mini_msgs__msg__LightState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scout_mini_msgs__msg__LightState__Sequence__destroy(scout_mini_msgs__msg__LightState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scout_mini_msgs__msg__LightState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scout_mini_msgs__msg__LightState__Sequence__are_equal(const scout_mini_msgs__msg__LightState__Sequence * lhs, const scout_mini_msgs__msg__LightState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scout_mini_msgs__msg__LightState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scout_mini_msgs__msg__LightState__Sequence__copy(
  const scout_mini_msgs__msg__LightState__Sequence * input,
  scout_mini_msgs__msg__LightState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scout_mini_msgs__msg__LightState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scout_mini_msgs__msg__LightState * data =
      (scout_mini_msgs__msg__LightState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scout_mini_msgs__msg__LightState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scout_mini_msgs__msg__LightState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scout_mini_msgs__msg__LightState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
