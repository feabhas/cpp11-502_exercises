// Lamp.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef LAMP_H
#define LAMP_H

#include "Device.h"

namespace Home
{
  struct Lamp
  {
    Device device;
    bool   state;
  };

  void Lamp_on(Lamp& lamp);
  void Lamp_off(Lamp& lamp);

  Lamp make_lamp(House house, Unit unit);

} // namespace Home

#endif // LAMP_H_
