// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_detector:msg/YoloDetection.idl
// generated code does not contain a copyright notice

#ifndef TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__BUILDER_HPP_
#define TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_detector/msg/detail/yolo_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_detector
{

namespace msg
{

namespace builder
{

class Init_YoloDetection_ymax
{
public:
  explicit Init_YoloDetection_ymax(::test_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  ::test_detector::msg::YoloDetection ymax(::test_detector::msg::YoloDetection::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_xmax
{
public:
  explicit Init_YoloDetection_xmax(::test_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_ymax xmax(::test_detector::msg::YoloDetection::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_YoloDetection_ymax(msg_);
  }

private:
  ::test_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_ymin
{
public:
  explicit Init_YoloDetection_ymin(::test_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_xmax ymin(::test_detector::msg::YoloDetection::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_YoloDetection_xmax(msg_);
  }

private:
  ::test_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_xmin
{
public:
  explicit Init_YoloDetection_xmin(::test_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_ymin xmin(::test_detector::msg::YoloDetection::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_YoloDetection_ymin(msg_);
  }

private:
  ::test_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_confidence
{
public:
  explicit Init_YoloDetection_confidence(::test_detector::msg::YoloDetection & msg)
  : msg_(msg)
  {}
  Init_YoloDetection_xmin confidence(::test_detector::msg::YoloDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_YoloDetection_xmin(msg_);
  }

private:
  ::test_detector::msg::YoloDetection msg_;
};

class Init_YoloDetection_class_id
{
public:
  Init_YoloDetection_class_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloDetection_confidence class_id(::test_detector::msg::YoloDetection::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_YoloDetection_confidence(msg_);
  }

private:
  ::test_detector::msg::YoloDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_detector::msg::YoloDetection>()
{
  return test_detector::msg::builder::Init_YoloDetection_class_id();
}

}  // namespace test_detector

#endif  // TEST_DETECTOR__MSG__DETAIL__YOLO_DETECTION__BUILDER_HPP_
