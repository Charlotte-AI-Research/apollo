// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from scout_mini_msgs:msg/LightState.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__FUNCTIONS_H_
#define SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "scout_mini_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "scout_mini_msgs/msg/detail/light_state__struct.h"

/// Initialize msg/LightState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * scout_mini_msgs__msg__LightState
 * )) before or use
 * scout_mini_msgs__msg__LightState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
bool
scout_mini_msgs__msg__LightState__init(scout_mini_msgs__msg__LightState * msg);

/// Finalize msg/LightState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
void
scout_mini_msgs__msg__LightState__fini(scout_mini_msgs__msg__LightState * msg);

/// Create msg/LightState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * scout_mini_msgs__msg__LightState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
scout_mini_msgs__msg__LightState *
scout_mini_msgs__msg__LightState__create();

/// Destroy msg/LightState message.
/**
 * It calls
 * scout_mini_msgs__msg__LightState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
void
scout_mini_msgs__msg__LightState__destroy(scout_mini_msgs__msg__LightState * msg);

/// Check for msg/LightState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
bool
scout_mini_msgs__msg__LightState__are_equal(const scout_mini_msgs__msg__LightState * lhs, const scout_mini_msgs__msg__LightState * rhs);

/// Copy a msg/LightState message.
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
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
bool
scout_mini_msgs__msg__LightState__copy(
  const scout_mini_msgs__msg__LightState * input,
  scout_mini_msgs__msg__LightState * output);

/// Initialize array of msg/LightState messages.
/**
 * It allocates the memory for the number of elements and calls
 * scout_mini_msgs__msg__LightState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
bool
scout_mini_msgs__msg__LightState__Sequence__init(scout_mini_msgs__msg__LightState__Sequence * array, size_t size);

/// Finalize array of msg/LightState messages.
/**
 * It calls
 * scout_mini_msgs__msg__LightState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
void
scout_mini_msgs__msg__LightState__Sequence__fini(scout_mini_msgs__msg__LightState__Sequence * array);

/// Create array of msg/LightState messages.
/**
 * It allocates the memory for the array and calls
 * scout_mini_msgs__msg__LightState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
scout_mini_msgs__msg__LightState__Sequence *
scout_mini_msgs__msg__LightState__Sequence__create(size_t size);

/// Destroy array of msg/LightState messages.
/**
 * It calls
 * scout_mini_msgs__msg__LightState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
void
scout_mini_msgs__msg__LightState__Sequence__destroy(scout_mini_msgs__msg__LightState__Sequence * array);

/// Check for msg/LightState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
bool
scout_mini_msgs__msg__LightState__Sequence__are_equal(const scout_mini_msgs__msg__LightState__Sequence * lhs, const scout_mini_msgs__msg__LightState__Sequence * rhs);

/// Copy an array of msg/LightState messages.
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
ROSIDL_GENERATOR_C_PUBLIC_scout_mini_msgs
bool
scout_mini_msgs__msg__LightState__Sequence__copy(
  const scout_mini_msgs__msg__LightState__Sequence * input,
  scout_mini_msgs__msg__LightState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SCOUT_MINI_MSGS__MSG__DETAIL__LIGHT_STATE__FUNCTIONS_H_
