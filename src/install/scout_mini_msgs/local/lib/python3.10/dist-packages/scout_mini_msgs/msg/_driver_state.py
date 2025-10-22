# generated from rosidl_generator_py/resource/_idl.py.em
# with input from scout_mini_msgs:msg/DriverState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'driver_voltage'
# Member 'driver_temperature'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DriverState(type):
    """Metaclass of message 'DriverState'."""

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
                'scout_mini_msgs.msg.DriverState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__driver_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__driver_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__driver_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__driver_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__driver_state

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


class DriverState(metaclass=Metaclass_DriverState):
    """Message class 'DriverState'."""

    __slots__ = [
        '_header',
        '_driver_voltage',
        '_driver_temperature',
        '_communication_failure',
        '_low_supply_voltage',
        '_motor_over_temperature',
        '_driver_over_current',
        '_driver_over_temperature',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'driver_voltage': 'double[4]',
        'driver_temperature': 'int16[4]',
        'communication_failure': 'boolean[4]',
        'low_supply_voltage': 'boolean[4]',
        'motor_over_temperature': 'boolean[4]',
        'driver_over_current': 'boolean[4]',
        'driver_over_temperature': 'boolean[4]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int16'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('boolean'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('boolean'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('boolean'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('boolean'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('boolean'), 4),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        if 'driver_voltage' not in kwargs:
            self.driver_voltage = numpy.zeros(4, dtype=numpy.float64)
        else:
            self.driver_voltage = numpy.array(kwargs.get('driver_voltage'), dtype=numpy.float64)
            assert self.driver_voltage.shape == (4, )
        if 'driver_temperature' not in kwargs:
            self.driver_temperature = numpy.zeros(4, dtype=numpy.int16)
        else:
            self.driver_temperature = numpy.array(kwargs.get('driver_temperature'), dtype=numpy.int16)
            assert self.driver_temperature.shape == (4, )
        self.communication_failure = kwargs.get(
            'communication_failure',
            [bool() for x in range(4)]
        )
        self.low_supply_voltage = kwargs.get(
            'low_supply_voltage',
            [bool() for x in range(4)]
        )
        self.motor_over_temperature = kwargs.get(
            'motor_over_temperature',
            [bool() for x in range(4)]
        )
        self.driver_over_current = kwargs.get(
            'driver_over_current',
            [bool() for x in range(4)]
        )
        self.driver_over_temperature = kwargs.get(
            'driver_over_temperature',
            [bool() for x in range(4)]
        )

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
        if any(self.driver_voltage != other.driver_voltage):
            return False
        if any(self.driver_temperature != other.driver_temperature):
            return False
        if self.communication_failure != other.communication_failure:
            return False
        if self.low_supply_voltage != other.low_supply_voltage:
            return False
        if self.motor_over_temperature != other.motor_over_temperature:
            return False
        if self.driver_over_current != other.driver_over_current:
            return False
        if self.driver_over_temperature != other.driver_over_temperature:
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
    def driver_voltage(self):
        """Message field 'driver_voltage'."""
        return self._driver_voltage

    @driver_voltage.setter
    def driver_voltage(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'driver_voltage' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 4, \
                "The 'driver_voltage' numpy.ndarray() must have a size of 4"
            self._driver_voltage = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'driver_voltage' field must be a set or sequence with length 4 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._driver_voltage = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def driver_temperature(self):
        """Message field 'driver_temperature'."""
        return self._driver_temperature

    @driver_temperature.setter
    def driver_temperature(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int16, \
                "The 'driver_temperature' numpy.ndarray() must have the dtype of 'numpy.int16'"
            assert value.size == 4, \
                "The 'driver_temperature' numpy.ndarray() must have a size of 4"
            self._driver_temperature = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -32768 and val < 32768 for val in value)), \
                "The 'driver_temperature' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-32768, 32767]"
        self._driver_temperature = numpy.array(value, dtype=numpy.int16)

    @builtins.property
    def communication_failure(self):
        """Message field 'communication_failure'."""
        return self._communication_failure

    @communication_failure.setter
    def communication_failure(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'communication_failure' field must be a set or sequence with length 4 and each value of type 'bool'"
        self._communication_failure = value

    @builtins.property
    def low_supply_voltage(self):
        """Message field 'low_supply_voltage'."""
        return self._low_supply_voltage

    @low_supply_voltage.setter
    def low_supply_voltage(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'low_supply_voltage' field must be a set or sequence with length 4 and each value of type 'bool'"
        self._low_supply_voltage = value

    @builtins.property
    def motor_over_temperature(self):
        """Message field 'motor_over_temperature'."""
        return self._motor_over_temperature

    @motor_over_temperature.setter
    def motor_over_temperature(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'motor_over_temperature' field must be a set or sequence with length 4 and each value of type 'bool'"
        self._motor_over_temperature = value

    @builtins.property
    def driver_over_current(self):
        """Message field 'driver_over_current'."""
        return self._driver_over_current

    @driver_over_current.setter
    def driver_over_current(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'driver_over_current' field must be a set or sequence with length 4 and each value of type 'bool'"
        self._driver_over_current = value

    @builtins.property
    def driver_over_temperature(self):
        """Message field 'driver_over_temperature'."""
        return self._driver_over_temperature

    @driver_over_temperature.setter
    def driver_over_temperature(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'driver_over_temperature' field must be a set or sequence with length 4 and each value of type 'bool'"
        self._driver_over_temperature = value
