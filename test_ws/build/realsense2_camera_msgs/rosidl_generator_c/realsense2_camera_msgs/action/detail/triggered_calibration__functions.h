// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from realsense2_camera_msgs:action/TriggeredCalibration.idl
// generated code does not contain a copyright notice

#ifndef REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__FUNCTIONS_H_
#define REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "realsense2_camera_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "realsense2_camera_msgs/action/detail/triggered_calibration__struct.h"

/// Initialize action/TriggeredCalibration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * realsense2_camera_msgs__action__TriggeredCalibration_Goal
 * )) before or use
 * realsense2_camera_msgs__action__TriggeredCalibration_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__init(realsense2_camera_msgs__action__TriggeredCalibration_Goal * msg);

/// Finalize action/TriggeredCalibration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Goal__fini(realsense2_camera_msgs__action__TriggeredCalibration_Goal * msg);

/// Create action/TriggeredCalibration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_Goal *
realsense2_camera_msgs__action__TriggeredCalibration_Goal__create();

/// Destroy action/TriggeredCalibration message.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Goal__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Goal * msg);

/// Check for action/TriggeredCalibration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Goal * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Goal * rhs);

/// Copy a action/TriggeredCalibration message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Goal * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Goal * output);

/// Initialize array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the number of elements and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * array, size_t size);

/// Finalize array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * array);

/// Create array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the array and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__create(size_t size);

/// Destroy array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * array);

/// Check for action/TriggeredCalibration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * rhs);

/// Copy an array of action/TriggeredCalibration messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence * output);

/// Initialize action/TriggeredCalibration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * realsense2_camera_msgs__action__TriggeredCalibration_Result
 * )) before or use
 * realsense2_camera_msgs__action__TriggeredCalibration_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__init(realsense2_camera_msgs__action__TriggeredCalibration_Result * msg);

/// Finalize action/TriggeredCalibration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Result__fini(realsense2_camera_msgs__action__TriggeredCalibration_Result * msg);

/// Create action/TriggeredCalibration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_Result *
realsense2_camera_msgs__action__TriggeredCalibration_Result__create();

/// Destroy action/TriggeredCalibration message.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Result__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Result * msg);

/// Check for action/TriggeredCalibration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Result * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Result * rhs);

/// Copy a action/TriggeredCalibration message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Result * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Result * output);

/// Initialize array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the number of elements and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * array, size_t size);

/// Finalize array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * array);

/// Create array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the array and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__create(size_t size);

/// Destroy array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * array);

/// Check for action/TriggeredCalibration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * rhs);

/// Copy an array of action/TriggeredCalibration messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence * output);

/// Initialize action/TriggeredCalibration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * realsense2_camera_msgs__action__TriggeredCalibration_Feedback
 * )) before or use
 * realsense2_camera_msgs__action__TriggeredCalibration_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__init(realsense2_camera_msgs__action__TriggeredCalibration_Feedback * msg);

/// Finalize action/TriggeredCalibration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__fini(realsense2_camera_msgs__action__TriggeredCalibration_Feedback * msg);

/// Create action/TriggeredCalibration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_Feedback *
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__create();

/// Destroy action/TriggeredCalibration message.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Feedback * msg);

/// Check for action/TriggeredCalibration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Feedback * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Feedback * rhs);

/// Copy a action/TriggeredCalibration message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Feedback * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Feedback * output);

/// Initialize array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the number of elements and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * array, size_t size);

/// Finalize array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * array);

/// Create array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the array and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__create(size_t size);

/// Destroy array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * array);

/// Check for action/TriggeredCalibration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * rhs);

/// Copy an array of action/TriggeredCalibration messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence * output);

/// Initialize action/TriggeredCalibration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request
 * )) before or use
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__init(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * msg);

/// Finalize action/TriggeredCalibration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__fini(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * msg);

/// Create action/TriggeredCalibration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request *
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__create();

/// Destroy action/TriggeredCalibration message.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__destroy(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * msg);

/// Check for action/TriggeredCalibration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * rhs);

/// Copy a action/TriggeredCalibration message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * input,
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * output);

/// Initialize array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the number of elements and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * array);

/// Create array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the array and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * array);

/// Check for action/TriggeredCalibration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/TriggeredCalibration messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence * output);

/// Initialize action/TriggeredCalibration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response
 * )) before or use
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__init(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * msg);

/// Finalize action/TriggeredCalibration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__fini(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * msg);

/// Create action/TriggeredCalibration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response *
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__create();

/// Destroy action/TriggeredCalibration message.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__destroy(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * msg);

/// Check for action/TriggeredCalibration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * rhs);

/// Copy a action/TriggeredCalibration message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * input,
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * output);

/// Initialize array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the number of elements and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * array);

/// Create array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the array and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * array);

/// Check for action/TriggeredCalibration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/TriggeredCalibration messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence * output);

/// Initialize action/TriggeredCalibration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request
 * )) before or use
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__init(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * msg);

/// Finalize action/TriggeredCalibration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__fini(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * msg);

/// Create action/TriggeredCalibration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request *
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__create();

/// Destroy action/TriggeredCalibration message.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__destroy(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * msg);

/// Check for action/TriggeredCalibration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * rhs);

/// Copy a action/TriggeredCalibration message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * input,
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * output);

/// Initialize array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the number of elements and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * array);

/// Create array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the array and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * array);

/// Check for action/TriggeredCalibration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * rhs);

/// Copy an array of action/TriggeredCalibration messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence * output);

/// Initialize action/TriggeredCalibration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response
 * )) before or use
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__init(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * msg);

/// Finalize action/TriggeredCalibration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__fini(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * msg);

/// Create action/TriggeredCalibration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response *
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__create();

/// Destroy action/TriggeredCalibration message.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__destroy(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * msg);

/// Check for action/TriggeredCalibration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * rhs);

/// Copy a action/TriggeredCalibration message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * input,
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * output);

/// Initialize array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the number of elements and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * array);

/// Create array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the array and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * array);

/// Check for action/TriggeredCalibration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * rhs);

/// Copy an array of action/TriggeredCalibration messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence * output);

/// Initialize action/TriggeredCalibration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage
 * )) before or use
 * realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__init(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * msg);

/// Finalize action/TriggeredCalibration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__fini(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * msg);

/// Create action/TriggeredCalibration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage *
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__create();

/// Destroy action/TriggeredCalibration message.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__destroy(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * msg);

/// Check for action/TriggeredCalibration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * rhs);

/// Copy a action/TriggeredCalibration message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * input,
  realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * output);

/// Initialize array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the number of elements and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__init(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__fini(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * array);

/// Create array of action/TriggeredCalibration messages.
/**
 * It allocates the memory for the array and calls
 * realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence *
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/TriggeredCalibration messages.
/**
 * It calls
 * realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
void
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__destroy(realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * array);

/// Check for action/TriggeredCalibration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__are_equal(const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * lhs, const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/TriggeredCalibration messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_realsense2_camera_msgs
bool
realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence__copy(
  const realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * input,
  realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__FUNCTIONS_H_
