// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from scout_mini_msgs:msg/FaultState.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "scout_mini_msgs/msg/detail/fault_state__struct.h"
#include "scout_mini_msgs/msg/detail/fault_state__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool scout_mini_msgs__msg__fault_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("scout_mini_msgs.msg._fault_state.FaultState", full_classname_dest, 43) == 0);
  }
  scout_mini_msgs__msg__FaultState * ros_message = _ros_message;
  {  // battery_under_voltage_failure
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_under_voltage_failure");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->battery_under_voltage_failure = (Py_True == field);
    Py_DECREF(field);
  }
  {  // battery_under_voltage_alarm
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_under_voltage_alarm");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->battery_under_voltage_alarm = (Py_True == field);
    Py_DECREF(field);
  }
  {  // loss_remote_control
    PyObject * field = PyObject_GetAttrString(_pymsg, "loss_remote_control");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->loss_remote_control = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * scout_mini_msgs__msg__fault_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FaultState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("scout_mini_msgs.msg._fault_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FaultState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  scout_mini_msgs__msg__FaultState * ros_message = (scout_mini_msgs__msg__FaultState *)raw_ros_message;
  {  // battery_under_voltage_failure
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->battery_under_voltage_failure ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_under_voltage_failure", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // battery_under_voltage_alarm
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->battery_under_voltage_alarm ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_under_voltage_alarm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // loss_remote_control
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->loss_remote_control ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "loss_remote_control", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
