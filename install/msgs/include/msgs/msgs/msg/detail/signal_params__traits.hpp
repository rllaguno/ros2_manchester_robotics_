// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msgs:msg/SignalParams.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__SIGNAL_PARAMS__TRAITS_HPP_
#define MSGS__MSG__DETAIL__SIGNAL_PARAMS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "msgs/msg/detail/signal_params__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SignalParams & msg,
  std::ostream & out)
{
  out << "{";
  // member: type_signal
  {
    out << "type_signal: ";
    rosidl_generator_traits::value_to_yaml(msg.type_signal, out);
    out << ", ";
  }

  // member: amplitude
  {
    out << "amplitude: ";
    rosidl_generator_traits::value_to_yaml(msg.amplitude, out);
    out << ", ";
  }

  // member: frequency
  {
    out << "frequency: ";
    rosidl_generator_traits::value_to_yaml(msg.frequency, out);
    out << ", ";
  }

  // member: offset
  {
    out << "offset: ";
    rosidl_generator_traits::value_to_yaml(msg.offset, out);
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SignalParams & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type_signal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type_signal: ";
    rosidl_generator_traits::value_to_yaml(msg.type_signal, out);
    out << "\n";
  }

  // member: amplitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "amplitude: ";
    rosidl_generator_traits::value_to_yaml(msg.amplitude, out);
    out << "\n";
  }

  // member: frequency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frequency: ";
    rosidl_generator_traits::value_to_yaml(msg.frequency, out);
    out << "\n";
  }

  // member: offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset: ";
    rosidl_generator_traits::value_to_yaml(msg.offset, out);
    out << "\n";
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SignalParams & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace msgs

namespace rosidl_generator_traits
{

[[deprecated("use msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const msgs::msg::SignalParams & msg,
  std::ostream & out, size_t indentation = 0)
{
  msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const msgs::msg::SignalParams & msg)
{
  return msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<msgs::msg::SignalParams>()
{
  return "msgs::msg::SignalParams";
}

template<>
inline const char * name<msgs::msg::SignalParams>()
{
  return "msgs/msg/SignalParams";
}

template<>
struct has_fixed_size<msgs::msg::SignalParams>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<msgs::msg::SignalParams>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<msgs::msg::SignalParams>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSGS__MSG__DETAIL__SIGNAL_PARAMS__TRAITS_HPP_
