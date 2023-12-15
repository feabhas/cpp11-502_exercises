// Appliance.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef APPLIANCE_H
#define APPLIANCE_H

#include "Module.h"

namespace Home
{
  class Appliance : public Module {
  public:
    Appliance() = default;
    Appliance(House house, Unit unit);

    void on() override;
    void off() override;
  };

} // namespace Home

#endif // APPLIANCE_H_
