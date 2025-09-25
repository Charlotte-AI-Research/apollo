// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from realsense2_camera_msgs:action/TriggeredCalibration.idl
// generated code does not contain a copyright notice

#ifndef REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__STRUCT_H_
#define REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'json'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/TriggeredCalibration in the package realsense2_camera_msgs.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_Goal
{
  rosidl_runtime_c__String json;
} realsense2_camera_msgs__action__TriggeredCalibration_Goal;

// Struct for a sequence of realsense2_camera_msgs__action__TriggeredCalibration_Goal.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence
{
  realsense2_camera_msgs__action__TriggeredCalibration_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} realsense2_camera_msgs__action__TriggeredCalibration_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error_msg'
// Member 'calibration'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/TriggeredCalibration in the package realsense2_camera_msgs.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_Result
{
  bool success;
  rosidl_runtime_c__String error_msg;
  rosidl_runtime_c__String calibration;
  float health;
} realsense2_camera_msgs__action__TriggeredCalibration_Result;

// Struct for a sequence of realsense2_camera_msgs__action__TriggeredCalibration_Result.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence
{
  realsense2_camera_msgs__action__TriggeredCalibration_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} realsense2_camera_msgs__action__TriggeredCalibration_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/TriggeredCalibration in the package realsense2_camera_msgs.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_Feedback
{
  float progress;
} realsense2_camera_msgs__action__TriggeredCalibration_Feedback;

// Struct for a sequence of realsense2_camera_msgs__action__TriggeredCalibration_Feedback.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence
{
  realsense2_camera_msgs__action__TriggeredCalibration_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} realsense2_camera_msgs__action__TriggeredCalibration_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "realsense2_camera_msgs/action/detail/triggered_calibration__struct.h"

/// Struct defined in action/TriggeredCalibration in the package realsense2_camera_msgs.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  realsense2_camera_msgs__action__TriggeredCalibration_Goal goal;
} realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request;

// Struct for a sequence of realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence
{
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/TriggeredCalibration in the package realsense2_camera_msgs.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response;

// Struct for a sequence of realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence
{
  realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} realsense2_camera_msgs__action__TriggeredCalibration_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/TriggeredCalibration in the package realsense2_camera_msgs.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request;

// Struct for a sequence of realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence
{
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "realsense2_camera_msgs/action/detail/triggered_calibration__struct.h"

/// Struct defined in action/TriggeredCalibration in the package realsense2_camera_msgs.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response
{
  int8_t status;
  realsense2_camera_msgs__action__TriggeredCalibration_Result result;
} realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response;

// Struct for a sequence of realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence
{
  realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} realsense2_camera_msgs__action__TriggeredCalibration_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "realsense2_camera_msgs/action/detail/triggered_calibration__struct.h"

/// Struct defined in action/TriggeredCalibration in the package realsense2_camera_msgs.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  realsense2_camera_msgs__action__TriggeredCalibration_Feedback feedback;
} realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage;

// Struct for a sequence of realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage.
typedef struct realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence
{
  realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} realsense2_camera_msgs__action__TriggeredCalibration_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REALSENSE2_CAMERA_MSGS__ACTION__DETAIL__TRIGGERED_CALIBRATION__STRUCT_H_
