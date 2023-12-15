// Module.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef MODULE_H
#define MODULE_H

#include "Device.h"
#include "Switchable.h"

namespace Home
{
  class Module : public Switchable {
  public:
    Module() = default;
    Module(House house, Unit unit) : device{ house, unit } {}
    virtual ~Module() = default;

    void   set_id(const Device& device);
    Device id() const;

    virtual void on()  = 0;
    virtual void off() = 0;
    bool         is_on() const;

    void status() const;

  protected:
    void switch_on();
    void switch_off();

  private:
    void print() const;

    Device device{};
    bool   state{};
  };

} // namespace Home

#endif // MODULE_H_
