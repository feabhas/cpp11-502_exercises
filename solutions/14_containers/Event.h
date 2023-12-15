// Event.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef EVENT_H
#define EVENT_H

#include "Instant.h"
#include "Room.h"

namespace Timing
{
  class Event {
  public:
    Event() = default;
    Event(const Instant& on_time, const Instant& off_time, Home::Room& room);

    void do_action(const Instant& time);

  private:
    Instant     on{};
    Instant     off{};
    Home::Room* room{};
  };

} // namespace Timing

#endif // EVENT_H_
