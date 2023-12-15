// NamedLamp.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef NAMED_LAMP_H
#define NAMED_LAMP_H

#include "Lamp.h"
#include <string_view>

namespace Home
{
  class NamedLamp : public Lamp {
  public:
    NamedLamp() = default;

    NamedLamp(House house, Unit unit, std::string_view str) :
      Lamp{ house, unit }, name{ str }
    {
    }

    void on() override;
    void off() override;

  private:
    std::string_view name{};
  };

} // namespace Home

#endif // NAMED_LAMP_H
