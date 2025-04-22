// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from scout_object_detector:msg/YoloDetection.idl
// generated code does not contain a copyright notice
#include "scout_object_detector/msg/detail/yolo_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `class_label`
#include "rosidl_runtime_c/string_functions.h"

bool
scout_object_detector__msg__YoloDetection__init(scout_object_detector__msg__YoloDetection * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // class_label
  if (!rosidl_runtime_c__String__init(&msg->class_label)) {
    scout_object_detector__msg__YoloDetection__fini(msg);
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
scout_object_detector__msg__YoloDetection__fini(scout_object_detector__msg__YoloDetection * msg)
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
scout_object_detector__msg__YoloDetection__are_equal(const scout_object_detector__msg__YoloDetection * lhs, const scout_object_detector__msg__YoloDetection * rhs)
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
scout_object_detector__msg__YoloDetection__copy(
  const scout_object_detector__msg__YoloDetection * input,
  scout_object_detector__msg__YoloDetection * output)
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

scout_object_detector__msg__YoloDetection *
scout_object_detector__msg__YoloDetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_object_detector__msg__YoloDetection * msg = (scout_object_detector__msg__YoloDetection *)allocator.allocate(sizeof(scout_object_detector__msg__YoloDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(scout_object_detector__msg__YoloDetection));
  bool success = scout_object_detector__msg__YoloDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
scout_object_detector__msg__YoloDetection__destroy(scout_object_detector__msg__YoloDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    scout_object_detector__msg__YoloDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
scout_object_detector__msg__YoloDetection__Sequence__init(scout_object_detector__msg__YoloDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_object_detector__msg__YoloDetection * data = NULL;

  if (size) {
    data = (scout_object_detector__msg__YoloDetection *)allocator.zero_allocate(size, sizeof(scout_object_detector__msg__YoloDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = scout_object_detector__msg__YoloDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        scout_object_detector__msg__YoloDetection__fini(&data[i - 1]);
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
scout_object_detector__msg__YoloDetection__Sequence__fini(scout_object_detector__msg__YoloDetection__Sequence * array)
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
      scout_object_detector__msg__YoloDetection__fini(&array->data[i]);
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

scout_object_detector__msg__YoloDetection__Sequence *
scout_object_detector__msg__YoloDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  scout_object_detector__msg__YoloDetection__Sequence * array = (scout_object_detector__msg__YoloDetection__Sequence *)allocator.allocate(sizeof(scout_object_detector__msg__YoloDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = scout_object_detector__msg__YoloDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
scout_object_detector__msg__YoloDetection__Sequence__destroy(scout_object_detector__msg__YoloDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    scout_object_detector__msg__YoloDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
scout_object_detector__msg__YoloDetection__Sequence__are_equal(const scout_object_detector__msg__YoloDetection__Sequence * lhs, const scout_object_detector__msg__YoloDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!scout_object_detector__msg__YoloDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
scout_object_detector__msg__YoloDetection__Sequence__copy(
  const scout_object_detector__msg__YoloDetection__Sequence * input,
  scout_object_detector__msg__YoloDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(scout_object_detector__msg__YoloDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    scout_object_detector__msg__YoloDetection * data =
      (scout_object_detector__msg__YoloDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!scout_object_detector__msg__YoloDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          scout_object_detector__msg__YoloDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!scout_object_detector__msg__YoloDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
