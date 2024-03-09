// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs:msg/SignalParams.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__SIGNAL_PARAMS__STRUCT_HPP_
#define MSGS__MSG__DETAIL__SIGNAL_PARAMS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__msgs__msg__SignalParams __attribute__((deprecated))
#else
# define DEPRECATED__msgs__msg__SignalParams __declspec(deprecated)
#endif

namespace msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SignalParams_
{
  using Type = SignalParams_<ContainerAllocator>;

  explicit SignalParams_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type_signal = 0l;
      this->amplitude = 0.0f;
      this->frequency = 0.0f;
      this->offset = 0.0f;
      this->time = 0.0f;
    }
  }

  explicit SignalParams_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type_signal = 0l;
      this->amplitude = 0.0f;
      this->frequency = 0.0f;
      this->offset = 0.0f;
      this->time = 0.0f;
    }
  }

  // field types and members
  using _type_signal_type =
    int32_t;
  _type_signal_type type_signal;
  using _amplitude_type =
    float;
  _amplitude_type amplitude;
  using _frequency_type =
    float;
  _frequency_type frequency;
  using _offset_type =
    float;
  _offset_type offset;
  using _time_type =
    float;
  _time_type time;

  // setters for named parameter idiom
  Type & set__type_signal(
    const int32_t & _arg)
  {
    this->type_signal = _arg;
    return *this;
  }
  Type & set__amplitude(
    const float & _arg)
  {
    this->amplitude = _arg;
    return *this;
  }
  Type & set__frequency(
    const float & _arg)
  {
    this->frequency = _arg;
    return *this;
  }
  Type & set__offset(
    const float & _arg)
  {
    this->offset = _arg;
    return *this;
  }
  Type & set__time(
    const float & _arg)
  {
    this->time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs::msg::SignalParams_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs::msg::SignalParams_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs::msg::SignalParams_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs::msg::SignalParams_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs::msg::SignalParams_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::SignalParams_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs::msg::SignalParams_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::SignalParams_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs::msg::SignalParams_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs::msg::SignalParams_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs__msg__SignalParams
    std::shared_ptr<msgs::msg::SignalParams_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs__msg__SignalParams
    std::shared_ptr<msgs::msg::SignalParams_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SignalParams_ & other) const
  {
    if (this->type_signal != other.type_signal) {
      return false;
    }
    if (this->amplitude != other.amplitude) {
      return false;
    }
    if (this->frequency != other.frequency) {
      return false;
    }
    if (this->offset != other.offset) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    return true;
  }
  bool operator!=(const SignalParams_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SignalParams_

// alias to use template instance with default allocator
using SignalParams =
  msgs::msg::SignalParams_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__SIGNAL_PARAMS__STRUCT_HPP_
