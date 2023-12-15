// instant.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Instant.h"
#include <iomanip>
#include <iostream>

namespace Timing
{
  Instant::Instant(Hour hr, Minute min) :
    hour{ static_cast<Hour>(hr % 24) }, minute{ static_cast<Minute>(min % 60) }
  {
  }

  bool Instant::is_equal(const Instant& rhs) const
  {
    return ((hour == rhs.hour) && (minute == rhs.minute));
  }

  void Instant::print() const
  {
    std::cout << "\nTime: " << std::setw(2) << std::setfill('0')
              << static_cast<int>(hour) << ':' << std::setw(2)
              << std::setfill('0') << static_cast<int>(minute) << '\n';
  }
} // namespace Timing
