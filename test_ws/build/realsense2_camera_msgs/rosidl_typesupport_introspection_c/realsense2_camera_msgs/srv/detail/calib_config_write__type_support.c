// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from realsense2_camera_msgs:srv/CalibConfigWrite.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "realsense2_camera_msgs/srv/detail/calib_config_write__rosidl_typesupport_introspection_c.h"
#include "realsense2_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "realsense2_camera_msgs/srv/detail/calib_config_write__functions.h"
#include "realsense2_camera_msgs/srv/detail/calib_config_write__struct.h"


// Include directives for member types
// Member `calib_config`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  realsense2_camera_msgs__srv__CalibConfigWrite_Request__init(message_memory);
}

void realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_fini_function(void * message_memory)
{
  realsense2_camera_msgs__srv__CalibConfigWrite_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_message_member_array[1] = {
  {
    "calib_config",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(realsense2_camera_msgs__srv__CalibConfigWrite_Request, calib_config),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_message_members = {
  "realsense2_camera_msgs__srv",  // message namespace
  "CalibConfigWrite_Request",  // message name
  1,  // number of fields
  sizeof(realsense2_camera_msgs__srv__CalibConfigWrite_Request),
  realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_message_member_array,  // message members
  realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_message_type_support_handle = {
  0,
  &realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_realsense2_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, realsense2_camera_msgs, srv, CalibConfigWrite_Request)() {
  if (!realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_message_type_support_handle.typesupport_identifier) {
    realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &realsense2_camera_msgs__srv__CalibConfigWrite_Request__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "realsense2_camera_msgs/srv/detail/calib_config_write__rosidl_typesupport_introspection_c.h"
// already included above
// #include "realsense2_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "realsense2_camera_msgs/srv/detail/calib_config_write__functions.h"
// already included above
// #include "realsense2_camera_msgs/srv/detail/calib_config_write__struct.h"


// Include directives for member types
// Member `error_message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  realsense2_camera_msgs__srv__CalibConfigWrite_Response__init(message_memory);
}

void realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_fini_function(void * message_memory)
{
  realsense2_camera_msgs__srv__CalibConfigWrite_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(realsense2_camera_msgs__srv__CalibConfigWrite_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(realsense2_camera_msgs__srv__CalibConfigWrite_Response, error_message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_message_members = {
  "realsense2_camera_msgs__srv",  // message namespace
  "CalibConfigWrite_Response",  // message name
  2,  // number of fields
  sizeof(realsense2_camera_msgs__srv__CalibConfigWrite_Response),
  realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_message_member_array,  // message members
  realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_message_type_support_handle = {
  0,
  &realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_realsense2_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, realsense2_camera_msgs, srv, CalibConfigWrite_Response)() {
  if (!realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_message_type_support_handle.typesupport_identifier) {
    realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &realsense2_camera_msgs__srv__CalibConfigWrite_Response__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "realsense2_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "realsense2_camera_msgs/srv/detail/calib_config_write__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers realsense2_camera_msgs__srv__detail__calib_config_write__rosidl_typesupport_introspection_c__CalibConfigWrite_service_members = {
  "realsense2_camera_msgs__srv",  // service namespace
  "CalibConfigWrite",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // realsense2_camera_msgs__srv__detail__calib_config_write__rosidl_typesupport_introspection_c__CalibConfigWrite_Request_message_type_support_handle,
  NULL  // response message
  // realsense2_camera_msgs__srv__detail__calib_config_write__rosidl_typesupport_introspection_c__CalibConfigWrite_Response_message_type_support_handle
};

static rosidl_service_type_support_t realsense2_camera_msgs__srv__detail__calib_config_write__rosidl_typesupport_introspection_c__CalibConfigWrite_service_type_support_handle = {
  0,
  &realsense2_camera_msgs__srv__detail__calib_config_write__rosidl_typesupport_introspection_c__CalibConfigWrite_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, realsense2_camera_msgs, srv, CalibConfigWrite_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, realsense2_camera_msgs, srv, CalibConfigWrite_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_realsense2_camera_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, realsense2_camera_msgs, srv, CalibConfigWrite)() {
  if (!realsense2_camera_msgs__srv__detail__calib_config_write__rosidl_typesupport_introspection_c__CalibConfigWrite_service_type_support_handle.typesupport_identifier) {
    realsense2_camera_msgs__srv__detail__calib_config_write__rosidl_typesupport_introspection_c__CalibConfigWrite_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)realsense2_camera_msgs__srv__detail__calib_config_write__rosidl_typesupport_introspection_c__CalibConfigWrite_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, realsense2_camera_msgs, srv, CalibConfigWrite_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, realsense2_camera_msgs, srv, CalibConfigWrite_Response)()->data;
  }

  return &realsense2_camera_msgs__srv__detail__calib_config_write__rosidl_typesupport_introspection_c__CalibConfigWrite_service_type_support_handle;
}
