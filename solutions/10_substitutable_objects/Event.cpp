// Event.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Event.h"
#include <iostream>

namespace Timing
{
  Event::Event(const Instant& on_time,
               const Instant& off_time,
               Home::Room&    room) :
    on{ on_time },
    off{ off_time }, room{ &room }
  {
  }

  void Event::do_action(const Instant& time)
  {
    if (time.is_equal(on)) { room->all_on(); }
    if (time.is_equal(off)) { room->all_off(); }
  }

} // namespace Timing
