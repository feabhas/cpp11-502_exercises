// Switchable.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef SWITCHABLE_H
#define SWITCHABLE_H

namespace Home
{
  class Switchable {
  public:
    virtual void on()          = 0;
    virtual void off()         = 0;
    virtual bool is_on() const = 0;

    virtual ~Switchable() = default;
  };

} // namespace Home

#endif // I_SWITCHABLE_H_
