// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:msg/SignalParams.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__SIGNAL_PARAMS__BUILDER_HPP_
#define MSGS__MSG__DETAIL__SIGNAL_PARAMS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/msg/detail/signal_params__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace msg
{

namespace builder
{

class Init_SignalParams_time
{
public:
  explicit Init_SignalParams_time(::msgs::msg::SignalParams & msg)
  : msg_(msg)
  {}
  ::msgs::msg::SignalParams time(::msgs::msg::SignalParams::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::msg::SignalParams msg_;
};

class Init_SignalParams_offset
{
public:
  explicit Init_SignalParams_offset(::msgs::msg::SignalParams & msg)
  : msg_(msg)
  {}
  Init_SignalParams_time offset(::msgs::msg::SignalParams::_offset_type arg)
  {
    msg_.offset = std::move(arg);
    return Init_SignalParams_time(msg_);
  }

private:
  ::msgs::msg::SignalParams msg_;
};

class Init_SignalParams_frequency
{
public:
  explicit Init_SignalParams_frequency(::msgs::msg::SignalParams & msg)
  : msg_(msg)
  {}
  Init_SignalParams_offset frequency(::msgs::msg::SignalParams::_frequency_type arg)
  {
    msg_.frequency = std::move(arg);
    return Init_SignalParams_offset(msg_);
  }

private:
  ::msgs::msg::SignalParams msg_;
};

class Init_SignalParams_amplitude
{
public:
  explicit Init_SignalParams_amplitude(::msgs::msg::SignalParams & msg)
  : msg_(msg)
  {}
  Init_SignalParams_frequency amplitude(::msgs::msg::SignalParams::_amplitude_type arg)
  {
    msg_.amplitude = std::move(arg);
    return Init_SignalParams_frequency(msg_);
  }

private:
  ::msgs::msg::SignalParams msg_;
};

class Init_SignalParams_type_signal
{
public:
  Init_SignalParams_type_signal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SignalParams_amplitude type_signal(::msgs::msg::SignalParams::_type_signal_type arg)
  {
    msg_.type_signal = std::move(arg);
    return Init_SignalParams_amplitude(msg_);
  }

private:
  ::msgs::msg::SignalParams msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::msg::SignalParams>()
{
  return msgs::msg::builder::Init_SignalParams_type_signal();
}

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__SIGNAL_PARAMS__BUILDER_HPP_
