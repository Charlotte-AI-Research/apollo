// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from scout_object_detector:msg/YoloDetection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "scout_object_detector/msg/detail/yolo_detection__rosidl_typesupport_introspection_c.h"
#include "scout_object_detector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "scout_object_detector/msg/detail/yolo_detection__functions.h"
#include "scout_object_detector/msg/detail/yolo_detection__struct.h"


// Include directives for member types
// Member `class_name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  scout_object_detector__msg__YoloDetection__init(message_memory);
}

void scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_fini_function(void * message_memory)
{
  scout_object_detector__msg__YoloDetection__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_message_member_array[7] = {
  {
    "class_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_object_detector__msg__YoloDetection, class_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "class_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_object_detector__msg__YoloDetection, class_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_object_detector__msg__YoloDetection, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xmin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_object_detector__msg__YoloDetection, xmin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_object_detector__msg__YoloDetection, ymin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xmax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_object_detector__msg__YoloDetection, xmax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(scout_object_detector__msg__YoloDetection, ymax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_message_members = {
  "scout_object_detector__msg",  // message namespace
  "YoloDetection",  // message name
  7,  // number of fields
  sizeof(scout_object_detector__msg__YoloDetection),
  scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_message_member_array,  // message members
  scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_message_type_support_handle = {
  0,
  &scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_scout_object_detector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, scout_object_detector, msg, YoloDetection)() {
  if (!scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_message_type_support_handle.typesupport_identifier) {
    scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &scout_object_detector__msg__YoloDetection__rosidl_typesupport_introspection_c__YoloDetection_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
