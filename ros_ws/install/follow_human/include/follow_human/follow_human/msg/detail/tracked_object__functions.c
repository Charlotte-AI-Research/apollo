// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from follow_human:msg/TrackedObject.idl
// generated code does not contain a copyright notice
#include "follow_human/msg/detail/tracked_object__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `class_label`
#include "rosidl_runtime_c/string_functions.h"

bool
follow_human__msg__TrackedObject__init(follow_human__msg__TrackedObject * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // class_label
  if (!rosidl_runtime_c__String__init(&msg->class_label)) {
    follow_human__msg__TrackedObject__fini(msg);
    return false;
  }
  // confidence
  // x
  // y
  // width
  // height
  return true;
}

void
follow_human__msg__TrackedObject__fini(follow_human__msg__TrackedObject * msg)
{
  if (!msg) {
    return;
  }
  // id
  // class_label
  rosidl_runtime_c__String__fini(&msg->class_label);
  // confidence
  // x
  // y
  // width
  // height
}

bool
follow_human__msg__TrackedObject__are_equal(const follow_human__msg__TrackedObject * lhs, const follow_human__msg__TrackedObject * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // class_label
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->class_label), &(rhs->class_label)))
  {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  return true;
}

bool
follow_human__msg__TrackedObject__copy(
  const follow_human__msg__TrackedObject * input,
  follow_human__msg__TrackedObject * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // class_label
  if (!rosidl_runtime_c__String__copy(
      &(input->class_label), &(output->class_label)))
  {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // width
  output->width = input->width;
  // height
  output->height = input->height;
  return true;
}

follow_human__msg__TrackedObject *
follow_human__msg__TrackedObject__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_human__msg__TrackedObject * msg = (follow_human__msg__TrackedObject *)allocator.allocate(sizeof(follow_human__msg__TrackedObject), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_human__msg__TrackedObject));
  bool success = follow_human__msg__TrackedObject__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_human__msg__TrackedObject__destroy(follow_human__msg__TrackedObject * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_human__msg__TrackedObject__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_human__msg__TrackedObject__Sequence__init(follow_human__msg__TrackedObject__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_human__msg__TrackedObject * data = NULL;

  if (size) {
    data = (follow_human__msg__TrackedObject *)allocator.zero_allocate(size, sizeof(follow_human__msg__TrackedObject), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_human__msg__TrackedObject__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_human__msg__TrackedObject__fini(&data[i - 1]);
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
follow_human__msg__TrackedObject__Sequence__fini(follow_human__msg__TrackedObject__Sequence * array)
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
      follow_human__msg__TrackedObject__fini(&array->data[i]);
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

follow_human__msg__TrackedObject__Sequence *
follow_human__msg__TrackedObject__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_human__msg__TrackedObject__Sequence * array = (follow_human__msg__TrackedObject__Sequence *)allocator.allocate(sizeof(follow_human__msg__TrackedObject__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_human__msg__TrackedObject__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_human__msg__TrackedObject__Sequence__destroy(follow_human__msg__TrackedObject__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_human__msg__TrackedObject__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_human__msg__TrackedObject__Sequence__are_equal(const follow_human__msg__TrackedObject__Sequence * lhs, const follow_human__msg__TrackedObject__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_human__msg__TrackedObject__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_human__msg__TrackedObject__Sequence__copy(
  const follow_human__msg__TrackedObject__Sequence * input,
  follow_human__msg__TrackedObject__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_human__msg__TrackedObject);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_human__msg__TrackedObject * data =
      (follow_human__msg__TrackedObject *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_human__msg__TrackedObject__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_human__msg__TrackedObject__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_human__msg__TrackedObject__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
