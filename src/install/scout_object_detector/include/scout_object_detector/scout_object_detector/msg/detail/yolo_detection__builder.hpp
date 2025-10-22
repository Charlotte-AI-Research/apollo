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

class Init_YoloDetection_ymax
{
public:
  explicit Init_YoloDetection_ymax(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  ::scout_object_detector::msg::YoloDetection ymax(::scout_object_detector::msg::YoloDetection::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return std::move(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_xmax
{
public:
  explicit Init_YoloDetection_xmax(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_ymax xmax(::scout_object_detector::msg::YoloDetection::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_YoloDetection_ymax(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_ymin
{
public:
  explicit Init_YoloDetection_ymin(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_xmax ymin(::scout_object_detector::msg::YoloDetection::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_YoloDetection_xmax(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_xmin
{
public:
  explicit Init_YoloDetection_xmin(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_ymin xmin(::scout_object_detector::msg::YoloDetection::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_YoloDetection_ymin(msg_);
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
  Init_YoloDetection_xmin confidence(::scout_object_detector::msg::YoloDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_YoloDetection_xmin(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_class_id
{
public:
  explicit Init_YoloDetection_class_id(::scout_object_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_confidence class_id(::scout_object_detector::msg::YoloDetection::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_YoloDetection_confidence(msg_);
  }

private:
  ::scout_object_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_class_name
{
public:
  Init_YoloDetection_class_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloDetection_class_id class_name(::scout_object_detector::msg::YoloDetection::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_YoloDetection_class_id(msg_);
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
  return scout_object_detector::msg::builder::Init_YoloDetection_class_name();
}

}  // namespace scout_object_detector

#endif  // SCOUT_OBJECT_DETECTOR__MSG__DETAIL__YOLO_DETECTION__BUILDER_HPP_
