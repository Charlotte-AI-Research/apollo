// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from follow_human:msg/DepthEstimation.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__FUNCTIONS_H_
#define FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "follow_human/msg/rosidl_generator_c__visibility_control.h"

#include "follow_human/msg/detail/depth_estimation__struct.h"

/// Initialize msg/DepthEstimation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_human__msg__DepthEstimation
 * )) before or use
 * follow_human__msg__DepthEstimation__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_human
bool
follow_human__msg__DepthEstimation__init(follow_human__msg__DepthEstimation * msg);

/// Finalize msg/DepthEstimation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_human
void
follow_human__msg__DepthEstimation__fini(follow_human__msg__DepthEstimation * msg);

/// Create msg/DepthEstimation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_human__msg__DepthEstimation__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_human
follow_human__msg__DepthEstimation *
follow_human__msg__DepthEstimation__create();

/// Destroy msg/DepthEstimation message.
/**
 * It calls
 * follow_human__msg__DepthEstimation__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_human
void
follow_human__msg__DepthEstimation__destroy(follow_human__msg__DepthEstimation * msg);

/// Check for msg/DepthEstimation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_human
bool
follow_human__msg__DepthEstimation__are_equal(const follow_human__msg__DepthEstimation * lhs, const follow_human__msg__DepthEstimation * rhs);

/// Copy a msg/DepthEstimation message.
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
ROSIDL_GENERATOR_C_PUBLIC_follow_human
bool
follow_human__msg__DepthEstimation__copy(
  const follow_human__msg__DepthEstimation * input,
  follow_human__msg__DepthEstimation * output);

/// Initialize array of msg/DepthEstimation messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_human__msg__DepthEstimation__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_human
bool
follow_human__msg__DepthEstimation__Sequence__init(follow_human__msg__DepthEstimation__Sequence * array, size_t size);

/// Finalize array of msg/DepthEstimation messages.
/**
 * It calls
 * follow_human__msg__DepthEstimation__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_human
void
follow_human__msg__DepthEstimation__Sequence__fini(follow_human__msg__DepthEstimation__Sequence * array);

/// Create array of msg/DepthEstimation messages.
/**
 * It allocates the memory for the array and calls
 * follow_human__msg__DepthEstimation__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_human
follow_human__msg__DepthEstimation__Sequence *
follow_human__msg__DepthEstimation__Sequence__create(size_t size);

/// Destroy array of msg/DepthEstimation messages.
/**
 * It calls
 * follow_human__msg__DepthEstimation__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_human
void
follow_human__msg__DepthEstimation__Sequence__destroy(follow_human__msg__DepthEstimation__Sequence * array);

/// Check for msg/DepthEstimation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_human
bool
follow_human__msg__DepthEstimation__Sequence__are_equal(const follow_human__msg__DepthEstimation__Sequence * lhs, const follow_human__msg__DepthEstimation__Sequence * rhs);

/// Copy an array of msg/DepthEstimation messages.
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
ROSIDL_GENERATOR_C_PUBLIC_follow_human
bool
follow_human__msg__DepthEstimation__Sequence__copy(
  const follow_human__msg__DepthEstimation__Sequence * input,
  follow_human__msg__DepthEstimation__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__FUNCTIONS_H_
