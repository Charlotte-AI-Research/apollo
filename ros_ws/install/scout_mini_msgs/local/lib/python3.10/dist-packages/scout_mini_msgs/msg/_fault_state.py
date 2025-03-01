# generated from rosidl_generator_py/resource/_idl.py.em
# with input from scout_mini_msgs:msg/FaultState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FaultState(type):
    """Metaclass of message 'FaultState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('scout_mini_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'scout_mini_msgs.msg.FaultState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fault_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fault_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fault_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fault_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fault_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FaultState(metaclass=Metaclass_FaultState):
    """Message class 'FaultState'."""

    __slots__ = [
        '_battery_under_voltage_failure',
        '_battery_under_voltage_alarm',
        '_loss_remote_control',
    ]

    _fields_and_field_types = {
        'battery_under_voltage_failure': 'boolean',
        'battery_under_voltage_alarm': 'boolean',
        'loss_remote_control': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.battery_under_voltage_failure = kwargs.get('battery_under_voltage_failure', bool())
        self.battery_under_voltage_alarm = kwargs.get('battery_under_voltage_alarm', bool())
        self.loss_remote_control = kwargs.get('loss_remote_control', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.battery_under_voltage_failure != other.battery_under_voltage_failure:
            return False
        if self.battery_under_voltage_alarm != other.battery_under_voltage_alarm:
            return False
        if self.loss_remote_control != other.loss_remote_control:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def battery_under_voltage_failure(self):
        """Message field 'battery_under_voltage_failure'."""
        return self._battery_under_voltage_failure

    @battery_under_voltage_failure.setter
    def battery_under_voltage_failure(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'battery_under_voltage_failure' field must be of type 'bool'"
        self._battery_under_voltage_failure = value

    @builtins.property
    def battery_under_voltage_alarm(self):
        """Message field 'battery_under_voltage_alarm'."""
        return self._battery_under_voltage_alarm

    @battery_under_voltage_alarm.setter
    def battery_under_voltage_alarm(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'battery_under_voltage_alarm' field must be of type 'bool'"
        self._battery_under_voltage_alarm = value

    @builtins.property
    def loss_remote_control(self):
        """Message field 'loss_remote_control'."""
        return self._loss_remote_control

    @loss_remote_control.setter
    def loss_remote_control(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'loss_remote_control' field must be of type 'bool'"
        self._loss_remote_control = value
