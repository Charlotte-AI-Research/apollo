// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rslidar_msg:msg/RslidarPacket.idl
// generated code does not contain a copyright notice
#include "rslidar_msg/msg/detail/rslidar_packet__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rslidar_msg__msg__RslidarPacket__init(rslidar_msg__msg__RslidarPacket * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    rslidar_msg__msg__RslidarPacket__fini(msg);
    return false;
  }
  // is_difop
  // is_frame_begin
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    rslidar_msg__msg__RslidarPacket__fini(msg);
    return false;
  }
  return true;
}

void
rslidar_msg__msg__RslidarPacket__fini(rslidar_msg__msg__RslidarPacket * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // is_difop
  // is_frame_begin
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
rslidar_msg__msg__RslidarPacket__are_equal(const rslidar_msg__msg__RslidarPacket * lhs, const rslidar_msg__msg__RslidarPacket * rhs)
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
  // is_difop
  if (lhs->is_difop != rhs->is_difop) {
    return false;
  }
  // is_frame_begin
  if (lhs->is_frame_begin != rhs->is_frame_begin) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
rslidar_msg__msg__RslidarPacket__copy(
  const rslidar_msg__msg__RslidarPacket * input,
  rslidar_msg__msg__RslidarPacket * output)
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
  // is_difop
  output->is_difop = input->is_difop;
  // is_frame_begin
  output->is_frame_begin = input->is_frame_begin;
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

rslidar_msg__msg__RslidarPacket *
rslidar_msg__msg__RslidarPacket__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rslidar_msg__msg__RslidarPacket * msg = (rslidar_msg__msg__RslidarPacket *)allocator.allocate(sizeof(rslidar_msg__msg__RslidarPacket), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rslidar_msg__msg__RslidarPacket));
  bool success = rslidar_msg__msg__RslidarPacket__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rslidar_msg__msg__RslidarPacket__destroy(rslidar_msg__msg__RslidarPacket * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rslidar_msg__msg__RslidarPacket__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rslidar_msg__msg__RslidarPacket__Sequence__init(rslidar_msg__msg__RslidarPacket__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rslidar_msg__msg__RslidarPacket * data = NULL;

  if (size) {
    data = (rslidar_msg__msg__RslidarPacket *)allocator.zero_allocate(size, sizeof(rslidar_msg__msg__RslidarPacket), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rslidar_msg__msg__RslidarPacket__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rslidar_msg__msg__RslidarPacket__fini(&data[i - 1]);
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
rslidar_msg__msg__RslidarPacket__Sequence__fini(rslidar_msg__msg__RslidarPacket__Sequence * array)
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
      rslidar_msg__msg__RslidarPacket__fini(&array->data[i]);
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

rslidar_msg__msg__RslidarPacket__Sequence *
rslidar_msg__msg__RslidarPacket__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rslidar_msg__msg__RslidarPacket__Sequence * array = (rslidar_msg__msg__RslidarPacket__Sequence *)allocator.allocate(sizeof(rslidar_msg__msg__RslidarPacket__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rslidar_msg__msg__RslidarPacket__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rslidar_msg__msg__RslidarPacket__Sequence__destroy(rslidar_msg__msg__RslidarPacket__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rslidar_msg__msg__RslidarPacket__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rslidar_msg__msg__RslidarPacket__Sequence__are_equal(const rslidar_msg__msg__RslidarPacket__Sequence * lhs, const rslidar_msg__msg__RslidarPacket__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rslidar_msg__msg__RslidarPacket__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rslidar_msg__msg__RslidarPacket__Sequence__copy(
  const rslidar_msg__msg__RslidarPacket__Sequence * input,
  rslidar_msg__msg__RslidarPacket__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rslidar_msg__msg__RslidarPacket);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rslidar_msg__msg__RslidarPacket * data =
      (rslidar_msg__msg__RslidarPacket *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rslidar_msg__msg__RslidarPacket__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rslidar_msg__msg__RslidarPacket__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rslidar_msg__msg__RslidarPacket__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
