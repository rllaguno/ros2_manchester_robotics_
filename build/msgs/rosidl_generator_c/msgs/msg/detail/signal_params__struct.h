// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs:msg/SignalParams.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__SIGNAL_PARAMS__STRUCT_H_
#define MSGS__MSG__DETAIL__SIGNAL_PARAMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SignalParams in the package msgs.
typedef struct msgs__msg__SignalParams
{
  int32_t type_signal;
  float amplitude;
  float frequency;
  float offset;
  float time;
} msgs__msg__SignalParams;

// Struct for a sequence of msgs__msg__SignalParams.
typedef struct msgs__msg__SignalParams__Sequence
{
  msgs__msg__SignalParams * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__msg__SignalParams__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS__MSG__DETAIL__SIGNAL_PARAMS__STRUCT_H_
