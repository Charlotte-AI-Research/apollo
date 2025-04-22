// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from follow_human:msg/DepthEstimation.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__BUILDER_HPP_
#define FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "follow_human/msg/detail/depth_estimation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace follow_human
{

namespace msg
{

namespace builder
{

class Init_DepthEstimation_depth_m
{
public:
  explicit Init_DepthEstimation_depth_m(::follow_human::msg::DepthEstimation & msg)
  : msg_(msg)
  {}
  ::follow_human::msg::DepthEstimation depth_m(::follow_human::msg::DepthEstimation::_depth_m_type arg)
  {
    msg_.depth_m = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_human::msg::DepthEstimation msg_;
};

class Init_DepthEstimation_height
{
public:
  explicit Init_DepthEstimation_height(::follow_human::msg::DepthEstimation & msg)
  : msg_(msg)
  {}
  Init_DepthEstimation_depth_m height(::follow_human::msg::DepthEstimation::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_DepthEstimation_depth_m(msg_);
  }

private:
  ::follow_human::msg::DepthEstimation msg_;
};

class Init_DepthEstimation_width
{
public:
  explicit Init_DepthEstimation_width(::follow_human::msg::DepthEstimation & msg)
  : msg_(msg)
  {}
  Init_DepthEstimation_height width(::follow_human::msg::DepthEstimation::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_DepthEstimation_height(msg_);
  }

private:
  ::follow_human::msg::DepthEstimation msg_;
};

class Init_DepthEstimation_y
{
public:
  explicit Init_DepthEstimation_y(::follow_human::msg::DepthEstimation & msg)
  : msg_(msg)
  {}
  Init_DepthEstimation_width y(::follow_human::msg::DepthEstimation::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_DepthEstimation_width(msg_);
  }

private:
  ::follow_human::msg::DepthEstimation msg_;
};

class Init_DepthEstimation_x
{
public:
  explicit Init_DepthEstimation_x(::follow_human::msg::DepthEstimation & msg)
  : msg_(msg)
  {}
  Init_DepthEstimation_y x(::follow_human::msg::DepthEstimation::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_DepthEstimation_y(msg_);
  }

private:
  ::follow_human::msg::DepthEstimation msg_;
};

class Init_DepthEstimation_confidence
{
public:
  explicit Init_DepthEstimation_confidence(::follow_human::msg::DepthEstimation & msg)
  : msg_(msg)
  {}
  Init_DepthEstimation_x confidence(::follow_human::msg::DepthEstimation::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_DepthEstimation_x(msg_);
  }

private:
  ::follow_human::msg::DepthEstimation msg_;
};

class Init_DepthEstimation_class_label
{
public:
  explicit Init_DepthEstimation_class_label(::follow_human::msg::DepthEstimation & msg)
  : msg_(msg)
  {}
  Init_DepthEstimation_confidence class_label(::follow_human::msg::DepthEstimation::_class_label_type arg)
  {
    msg_.class_label = std::move(arg);
    return Init_DepthEstimation_confidence(msg_);
  }

private:
  ::follow_human::msg::DepthEstimation msg_;
};

class Init_DepthEstimation_id
{
public:
  Init_DepthEstimation_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DepthEstimation_class_label id(::follow_human::msg::DepthEstimation::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DepthEstimation_class_label(msg_);
  }

private:
  ::follow_human::msg::DepthEstimation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_human::msg::DepthEstimation>()
{
  return follow_human::msg::builder::Init_DepthEstimation_id();
}

}  // namespace follow_human

#endif  // FOLLOW_HUMAN__MSG__DETAIL__DEPTH_ESTIMATION__BUILDER_HPP_
