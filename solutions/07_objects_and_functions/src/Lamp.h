// Lamp.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef LAMP_H
#define LAMP_H

#include "Device.h"

namespace Home
{
  class Lamp {
  public:
    // Lamp() = default;
    Lamp();
    Lamp(House house, Unit unit, bool st = false);
    ~Lamp();

    void   set_id(const Device& device);
    Device id() const;

    void on();
    void off();
    bool is_on() const;

    void status() const;

  private:
    void print_lamp() const;

    Device device{};
    bool   state{};
  };

  Lamp make_lamp(House house, Unit unit);

} // namespace Home

#endif // LAMP_H_
