// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from follow_human:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "follow_human/msg/detail/tracked_object__struct.h"
#include "follow_human/msg/detail/tracked_object__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace follow_human
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _TrackedObject_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TrackedObject_type_support_ids_t;

static const _TrackedObject_type_support_ids_t _TrackedObject_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TrackedObject_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TrackedObject_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TrackedObject_type_support_symbol_names_t _TrackedObject_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, follow_human, msg, TrackedObject)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_human, msg, TrackedObject)),
  }
};

typedef struct _TrackedObject_type_support_data_t
{
  void * data[2];
} _TrackedObject_type_support_data_t;

static _TrackedObject_type_support_data_t _TrackedObject_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TrackedObject_message_typesupport_map = {
  2,
  "follow_human",
  &_TrackedObject_message_typesupport_ids.typesupport_identifier[0],
  &_TrackedObject_message_typesupport_symbol_names.symbol_name[0],
  &_TrackedObject_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TrackedObject_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TrackedObject_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace follow_human

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, follow_human, msg, TrackedObject)() {
  return &::follow_human::msg::rosidl_typesupport_c::TrackedObject_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
