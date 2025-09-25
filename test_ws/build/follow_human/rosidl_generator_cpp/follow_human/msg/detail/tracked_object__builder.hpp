// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from follow_human:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_HUMAN__MSG__DETAIL__TRACKED_OBJECT__BUILDER_HPP_
#define FOLLOW_HUMAN__MSG__DETAIL__TRACKED_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "follow_human/msg/detail/tracked_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace follow_human
{

namespace msg
{

namespace builder
{

class Init_TrackedObject_height
{
public:
  explicit Init_TrackedObject_height(::follow_human::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  ::follow_human::msg::TrackedObject height(::follow_human::msg::TrackedObject::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_human::msg::TrackedObject msg_;
};

class Init_TrackedObject_width
{
public:
  explicit Init_TrackedObject_width(::follow_human::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_height width(::follow_human::msg::TrackedObject::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_TrackedObject_height(msg_);
  }

private:
  ::follow_human::msg::TrackedObject msg_;
};

class Init_TrackedObject_y
{
public:
  explicit Init_TrackedObject_y(::follow_human::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_width y(::follow_human::msg::TrackedObject::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TrackedObject_width(msg_);
  }

private:
  ::follow_human::msg::TrackedObject msg_;
};

class Init_TrackedObject_x
{
public:
  explicit Init_TrackedObject_x(::follow_human::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_y x(::follow_human::msg::TrackedObject::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TrackedObject_y(msg_);
  }

private:
  ::follow_human::msg::TrackedObject msg_;
};

class Init_TrackedObject_confidence
{
public:
  explicit Init_TrackedObject_confidence(::follow_human::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_x confidence(::follow_human::msg::TrackedObject::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_TrackedObject_x(msg_);
  }

private:
  ::follow_human::msg::TrackedObject msg_;
};

class Init_TrackedObject_class_label
{
public:
  explicit Init_TrackedObject_class_label(::follow_human::msg::TrackedObject & msg)
  : msg_(msg)
  {}
  Init_TrackedObject_confidence class_label(::follow_human::msg::TrackedObject::_class_label_type arg)
  {
    msg_.class_label = std::move(arg);
    return Init_TrackedObject_confidence(msg_);
  }

private:
  ::follow_human::msg::TrackedObject msg_;
};

class Init_TrackedObject_id
{
public:
  Init_TrackedObject_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackedObject_class_label id(::follow_human::msg::TrackedObject::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_TrackedObject_class_label(msg_);
  }

private:
  ::follow_human::msg::TrackedObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_human::msg::TrackedObject>()
{
  return follow_human::msg::builder::Init_TrackedObject_id();
}

}  // namespace follow_human

#endif  // FOLLOW_HUMAN__MSG__DETAIL__TRACKED_OBJECT__BUILDER_HPP_
