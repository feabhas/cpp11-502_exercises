// EventList.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "EventList.h"
#include "Instant.h"

namespace Timing
{
  bool EventList::add_event(const Instant& on,
                            const Instant& off,
                            Home::Room&    room)
  {
    if (next == end(events)) return false; // Full-up!

    *next = std::make_unique<Event>(on, off, room);
    ++next;

    return true;
  }

  void EventList::update_time(const Instant& time)
  {
    time.print();
    for (auto& event : events) {
      if (event) { event->do_action(time); }
    }
  }

} // namespace Timing
