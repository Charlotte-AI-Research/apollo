// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from scout_object_detector:msg/YoloDetection.idl
// generated code does not contain a copyright notice

#ifndef SCOUT_OBJECT_DETECTOR__MSG__DETAIL__YOLO_DETECTION__BUILDER_HPP_
#define SCOUT_OBJECT_DETECTOR__MSG__DETAIL__YOLO_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "scout_object_detector/msg/detail/yolo_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace scout_object_detector
{

namespace msg
{

namespace builder
{

class Init_YoloDetection_height
{
public:
  explicit Init_YoloDetection_height(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  ::scout_object_detector::msg::YoloDetection height(::scout_object_detector::msg::YoloDetection::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_width
{
public:
  explicit Init_YoloDetection_width(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_height width(::scout_object_detector::msg::YoloDetection::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_YoloDetection_height(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_y
{
public:
  explicit Init_YoloDetection_y(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_width y(::scout_object_detector::msg::YoloDetection::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_YoloDetection_width(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_x
{
public:
  explicit Init_YoloDetection_x(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_y x(::scout_object_detector::msg::YoloDetection::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_YoloDetection_y(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_confidence
{
public:
  explicit Init_YoloDetection_confidence(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_x confidence(::scout_object_detector::msg::YoloDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_YoloDetection_x(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_class_label
{
public:
  explicit Init_YoloDetection_class_label(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_confidence class_label(::scout_object_detector::msg::YoloDetection::_class_label_type arg)
  {
    msg_.class_label = std::move(arg);
    return Init_YoloDetection_confidence(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_id
{
public:
  Init_YoloDetection_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloDetection_class_label id(::scout_object_detector::msg::YoloDetection::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_YoloDetection_class_label(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::scout_object_detector::msg::YoloDetection>()
{
  return scout_object_detector::msg::builder::Init_YoloDetection_id();
}

}  // namespace scout_object_detector

#endif  // SCOUT_OBJECT_DETECTOR__MSG__DETAIL__YOLO_DETECTION__BUILDER_HPP_
