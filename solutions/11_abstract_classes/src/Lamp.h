// Lamp.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef LAMP_H
#define LAMP_H

#include "Module.h"

namespace Home
{
  class Lamp : public Module {
  public:
    Lamp() = default;
    Lamp(House house, Unit unit);

    void on() override;
    void off() override;
  };

} // namespace Home

#endif // LAMP_H_
