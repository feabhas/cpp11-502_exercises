// Instant.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef INSTANT_H
#define INSTANT_H

#include <cstdint>
#include <iosfwd>

namespace Timing
{
  class Instant {
  public:
    using Hour   = std::uint8_t;
    using Minute = std::uint8_t;

    Instant() = default;
    explicit Instant(Hour hr, Minute min);

    bool is_equal(const Instant& rhs) const;

    void print() const;

  private:
    Hour   hour{ 99 };
    Minute minute{ 99 };
  };

} // namespace Timing

#endif // INSTANT_H_
