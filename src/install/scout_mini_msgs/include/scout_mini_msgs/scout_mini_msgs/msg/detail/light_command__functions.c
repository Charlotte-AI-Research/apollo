// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from scout_mini_msgs:msg/LightCommand.idl
// generated code does not contain a copyright notice
#include "scout_mini_msgs/msg/detail/light_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
scout_mini_msgs__msg__LightCommand__init(scout_mini_msgs__msg__LightCommand * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  // brightness
  return true;
}

void
scout_mini_msgs__msg__LightCommand__fini(scout_mini_msgs__msg__LightCommand * msg)
{
  if (!msg) {
    return;
  }
  // mode
  // brightness
}

bool
scout_mini_msgs__msg__LightCommand__are_equal(const scout_mini_msgs__msg__LightCommand * lhs, const scout_mini_msgs__msg__LightCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // brightness
  if (lhs->brightness != rhs->brightness) {
    return false;
  }
  return true;
}

bool
scout_mini_msgs__msg__LightCommand__copy(
  const scout_mini_msgs__msg__LightCommand * input,
  scout_mini_msgs__msg__LightCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  // brightness
  output->brightness = input->brightness;
  return true;
}

scout_mini_msgs__msg__LightCommand *
scout_mini_msgs__msg__LightCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__LightCommand * msg = (scout_mini_msgs__msg__LightCommand *)allocator.allocate(sizeof(scout_mini_msgs__msg__LightCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scout_mini_msgs__msg__LightCommand));
  bool success = scout_mini_msgs__msg__LightCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scout_mini_msgs__msg__LightCommand__destroy(scout_mini_msgs__msg__LightCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scout_mini_msgs__msg__LightCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scout_mini_msgs__msg__LightCommand__Sequence__init(scout_mini_msgs__msg__LightCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__LightCommand * data = NULL;

  if (size) {
    data = (scout_mini_msgs__msg__LightCommand *)allocator.zero_allocate(size, sizeof(scout_mini_msgs__msg__LightCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scout_mini_msgs__msg__LightCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scout_mini_msgs__msg__LightCommand__fini(&data[i - 1]);
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
scout_mini_msgs__msg__LightCommand__Sequence__fini(scout_mini_msgs__msg__LightCommand__Sequence * array)
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
      scout_mini_msgs__msg__LightCommand__fini(&array->data[i]);
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

scout_mini_msgs__msg__LightCommand__Sequence *
scout_mini_msgs__msg__LightCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_mini_msgs__msg__LightCommand__Sequence * array = (scout_mini_msgs__msg__LightCommand__Sequence *)allocator.allocate(sizeof(scout_mini_msgs__msg__LightCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scout_mini_msgs__msg__LightCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scout_mini_msgs__msg__LightCommand__Sequence__destroy(scout_mini_msgs__msg__LightCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scout_mini_msgs__msg__LightCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scout_mini_msgs__msg__LightCommand__Sequence__are_equal(const scout_mini_msgs__msg__LightCommand__Sequence * lhs, const scout_mini_msgs__msg__LightCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scout_mini_msgs__msg__LightCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scout_mini_msgs__msg__LightCommand__Sequence__copy(
  const scout_mini_msgs__msg__LightCommand__Sequence * input,
  scout_mini_msgs__msg__LightCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scout_mini_msgs__msg__LightCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scout_mini_msgs__msg__LightCommand * data =
      (scout_mini_msgs__msg__LightCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scout_mini_msgs__msg__LightCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scout_mini_msgs__msg__LightCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scout_mini_msgs__msg__LightCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
