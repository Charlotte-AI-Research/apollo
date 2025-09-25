# generated from rosidl_generator_py/resource/_idl.py.em
# with input from scout_mini_msgs:msg/RobotState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotState(type):
    """Metaclass of message 'RobotState'."""

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
                'scout_mini_msgs.msg.RobotState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_state

            from scout_mini_msgs.msg import FaultState
            if FaultState.__class__._TYPE_SUPPORT is None:
                FaultState.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotState(metaclass=Metaclass_RobotState):
    """Message class 'RobotState'."""

    __slots__ = [
        '_header',
        '_robot',
        '_normal_state',
        '_control_mode',
        '_battery_voltage',
        '_fault_state',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'robot': 'string',
        'normal_state': 'boolean',
        'control_mode': 'string',
        'battery_voltage': 'double',
        'fault_state': 'scout_mini_msgs/FaultState',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['scout_mini_msgs', 'msg'], 'FaultState'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.robot = kwargs.get('robot', str())
        self.normal_state = kwargs.get('normal_state', bool())
        self.control_mode = kwargs.get('control_mode', str())
        self.battery_voltage = kwargs.get('battery_voltage', float())
        from scout_mini_msgs.msg import FaultState
        self.fault_state = kwargs.get('fault_state', FaultState())

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
        if self.header != other.header:
            return False
        if self.robot != other.robot:
            return False
        if self.normal_state != other.normal_state:
            return False
        if self.control_mode != other.control_mode:
            return False
        if self.battery_voltage != other.battery_voltage:
            return False
        if self.fault_state != other.fault_state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def robot(self):
        """Message field 'robot'."""
        return self._robot

    @robot.setter
    def robot(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'robot' field must be of type 'str'"
        self._robot = value

    @builtins.property
    def normal_state(self):
        """Message field 'normal_state'."""
        return self._normal_state

    @normal_state.setter
    def normal_state(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'normal_state' field must be of type 'bool'"
        self._normal_state = value

    @builtins.property
    def control_mode(self):
        """Message field 'control_mode'."""
        return self._control_mode

    @control_mode.setter
    def control_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'control_mode' field must be of type 'str'"
        self._control_mode = value

    @builtins.property
    def battery_voltage(self):
        """Message field 'battery_voltage'."""
        return self._battery_voltage

    @battery_voltage.setter
    def battery_voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'battery_voltage' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'battery_voltage' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._battery_voltage = value

    @builtins.property
    def fault_state(self):
        """Message field 'fault_state'."""
        return self._fault_state

    @fault_state.setter
    def fault_state(self, value):
        if __debug__:
            from scout_mini_msgs.msg import FaultState
            assert \
                isinstance(value, FaultState), \
                "The 'fault_state' field must be a sub message of type 'FaultState'"
        self._fault_state = value
