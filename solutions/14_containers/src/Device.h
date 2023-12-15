// Device.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef DEVICE_H
#define DEVICE_H

#include <cstdint>

namespace Home
{
  enum class House : std::uint8_t { INVALID, A, B, C, D, E, F, G, H };

  using Unit = std::uint8_t;
  constexpr Unit Unit_min{ 1 };
  constexpr Unit Unit_max{ 16 };

  struct Device
  {
    House house;
    Unit  unit;
  };

} // namespace Home

#endif // DEVICE_H_
