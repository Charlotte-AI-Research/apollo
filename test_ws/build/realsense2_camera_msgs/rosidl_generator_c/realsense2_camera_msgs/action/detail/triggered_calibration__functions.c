// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from realsense2_camera_msgs:action/TriggeredCalibration.idl
// generated code does not contain a copyright notice
#include "realsense2_camera_msgs/action/detail/triggered_calibration__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `json`
#include "rosidl_runtime_c/string_functions.h"

bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__init(realsense2_camera_msgs__action__TriggeredCalibration_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // json
  if (!rosidl_runtime_c__String__init(&msg->json)) {
    realsense2_camera_msgs__action__TriggeredCalibration_Goal__fini(msg);
    return false;
  }
  {
    bool success = rosidl_runtime_c__String__assign(&msg->json, "calib run");
    if (!success) {
      goto abort_init_0;
    }
  }
  return true;
abort_init_0:
  return false;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_Goal__fini(realsense2_camera_msgs__action__TriggeredCalibration_Goal * msg)
{
  if (!msg) {
    return;
  }
  // json
  rosidl_runtime_c__String__fini(&msg->json);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Goal * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // json
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->json), &(rhs->json)))
  {
    return false;
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Goal * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // json
  if (!rosidl_runtime_c__String__copy(
      &(input->json), &(output->json)))
  {
    return false;
  }
  return true;
}

realsense2_camera_msgs__action__TriggeredCalibration_Goal *
realsense2_camera_msgs__action__TriggeredCalibration_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_Goal * msg = (realsense2_camera_msgs__action__TriggeredCalibration_Goal *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Goal));
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_Goal__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    realsense2_camera_msgs__action__TriggeredCalibration_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_Goal * data = NULL;

  if (size) {
    data = (realsense2_camera_msgs__action__TriggeredCalibration_Goal *)allocator.zero_allocate(size, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = realsense2_camera_msgs__action__TriggeredCalibration_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        realsense2_camera_msgs__action__TriggeredCalibration_Goal__fini(&data[i - 1]);
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
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * array)
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
      realsense2_camera_msgs__action__TriggeredCalibration_Goal__fini(&array->data[i]);
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

realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * array = (realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    realsense2_camera_msgs__action__TriggeredCalibration_Goal * data =
      (realsense2_camera_msgs__action__TriggeredCalibration_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!realsense2_camera_msgs__action__TriggeredCalibration_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          realsense2_camera_msgs__action__TriggeredCalibration_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `error_msg`
// Member `calibration`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__init(realsense2_camera_msgs__action__TriggeredCalibration_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // error_msg
  if (!rosidl_runtime_c__String__init(&msg->error_msg)) {
    realsense2_camera_msgs__action__TriggeredCalibration_Result__fini(msg);
    return false;
  }
  // calibration
  if (!rosidl_runtime_c__String__init(&msg->calibration)) {
    realsense2_camera_msgs__action__TriggeredCalibration_Result__fini(msg);
    return false;
  }
  // health
  return true;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_Result__fini(realsense2_camera_msgs__action__TriggeredCalibration_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // error_msg
  rosidl_runtime_c__String__fini(&msg->error_msg);
  // calibration
  rosidl_runtime_c__String__fini(&msg->calibration);
  // health
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Result * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // error_msg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_msg), &(rhs->error_msg)))
  {
    return false;
  }
  // calibration
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->calibration), &(rhs->calibration)))
  {
    return false;
  }
  // health
  if (lhs->health != rhs->health) {
    return false;
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Result * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // error_msg
  if (!rosidl_runtime_c__String__copy(
      &(input->error_msg), &(output->error_msg)))
  {
    return false;
  }
  // calibration
  if (!rosidl_runtime_c__String__copy(
      &(input->calibration), &(output->calibration)))
  {
    return false;
  }
  // health
  output->health = input->health;
  return true;
}

realsense2_camera_msgs__action__TriggeredCalibration_Result *
realsense2_camera_msgs__action__TriggeredCalibration_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_Result * msg = (realsense2_camera_msgs__action__TriggeredCalibration_Result *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Result));
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_Result__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    realsense2_camera_msgs__action__TriggeredCalibration_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_Result * data = NULL;

  if (size) {
    data = (realsense2_camera_msgs__action__TriggeredCalibration_Result *)allocator.zero_allocate(size, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = realsense2_camera_msgs__action__TriggeredCalibration_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        realsense2_camera_msgs__action__TriggeredCalibration_Result__fini(&data[i - 1]);
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
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * array)
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
      realsense2_camera_msgs__action__TriggeredCalibration_Result__fini(&array->data[i]);
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

realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * array = (realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    realsense2_camera_msgs__action__TriggeredCalibration_Result * data =
      (realsense2_camera_msgs__action__TriggeredCalibration_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!realsense2_camera_msgs__action__TriggeredCalibration_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          realsense2_camera_msgs__action__TriggeredCalibration_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__init(realsense2_camera_msgs__action__TriggeredCalibration_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // progress
  return true;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__fini(realsense2_camera_msgs__action__TriggeredCalibration_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // progress
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Feedback * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // progress
  if (lhs->progress != rhs->progress) {
    return false;
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Feedback * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // progress
  output->progress = input->progress;
  return true;
}

realsense2_camera_msgs__action__TriggeredCalibration_Feedback *
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_Feedback * msg = (realsense2_camera_msgs__action__TriggeredCalibration_Feedback *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Feedback));
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    realsense2_camera_msgs__action__TriggeredCalibration_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_Feedback * data = NULL;

  if (size) {
    data = (realsense2_camera_msgs__action__TriggeredCalibration_Feedback *)allocator.zero_allocate(size, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = realsense2_camera_msgs__action__TriggeredCalibration_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        realsense2_camera_msgs__action__TriggeredCalibration_Feedback__fini(&data[i - 1]);
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
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * array)
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
      realsense2_camera_msgs__action__TriggeredCalibration_Feedback__fini(&array->data[i]);
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

realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * array = (realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(realsense2_camera_msgs__action__TriggeredCalibration_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    realsense2_camera_msgs__action__TriggeredCalibration_Feedback * data =
      (realsense2_camera_msgs__action__TriggeredCalibration_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!realsense2_camera_msgs__action__TriggeredCalibration_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          realsense2_camera_msgs__action__TriggeredCalibration_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "realsense2_camera_msgs/action/detail/triggered_calibration__functions.h"

bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__init(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!realsense2_camera_msgs__action__TriggeredCalibration_Goal__init(&msg->goal)) {
    realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__fini(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  realsense2_camera_msgs__action__TriggeredCalibration_Goal__fini(&msg->goal);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!realsense2_camera_msgs__action__TriggeredCalibration_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * input,
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!realsense2_camera_msgs__action__TriggeredCalibration_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request *
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * msg = (realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request));
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__destroy(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * data = NULL;

  if (size) {
    data = (realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request *)allocator.zero_allocate(size, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__fini(&data[i - 1]);
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
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * array)
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
      realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__fini(&array->data[i]);
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

realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * array = (realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * data =
      (realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__init(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__fini(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * input,
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response *
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * msg = (realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response));
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__destroy(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * data = NULL;

  if (size) {
    data = (realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response *)allocator.zero_allocate(size, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__fini(&data[i - 1]);
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
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * array)
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
      realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__fini(&array->data[i]);
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

realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * array = (realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * data =
      (realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__init(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__fini(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * input,
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request *
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * msg = (realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request));
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__destroy(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * data = NULL;

  if (size) {
    data = (realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request *)allocator.zero_allocate(size, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__fini(&data[i - 1]);
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
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * array)
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
      realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__fini(&array->data[i]);
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

realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * array = (realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * data =
      (realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "realsense2_camera_msgs/action/detail/triggered_calibration__functions.h"

bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__init(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!realsense2_camera_msgs__action__TriggeredCalibration_Result__init(&msg->result)) {
    realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__fini(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  realsense2_camera_msgs__action__TriggeredCalibration_Result__fini(&msg->result);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!realsense2_camera_msgs__action__TriggeredCalibration_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * input,
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!realsense2_camera_msgs__action__TriggeredCalibration_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response *
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * msg = (realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response));
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__destroy(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * data = NULL;

  if (size) {
    data = (realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response *)allocator.zero_allocate(size, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__fini(&data[i - 1]);
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
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * array)
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
      realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__fini(&array->data[i]);
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

realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * array = (realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * data =
      (realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "realsense2_camera_msgs/action/detail/triggered_calibration__functions.h"

bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__init(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!realsense2_camera_msgs__action__TriggeredCalibration_Feedback__init(&msg->feedback)) {
    realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__fini(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  realsense2_camera_msgs__action__TriggeredCalibration_Feedback__fini(&msg->feedback);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!realsense2_camera_msgs__action__TriggeredCalibration_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * input,
  realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!realsense2_camera_msgs__action__TriggeredCalibration_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage *
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * msg = (realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage));
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__destroy(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * data = NULL;

  if (size) {
    data = (realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage *)allocator.zero_allocate(size, sizeof(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__fini(&data[i - 1]);
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
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * array)
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
      realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__fini(&array->data[i]);
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

realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * array = (realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence *)allocator.allocate(sizeof(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * data =
      (realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
