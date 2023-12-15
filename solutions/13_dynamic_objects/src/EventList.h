// EventList.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef EVENT_LIST_H
#define EVENT_LIST_H

#include "Event.h"
#include <array>
#include <memory>

namespace Timing
{
  class Instant;

  class EventList {
  public:
    bool add_event(const Instant& on, const Instant& off, Home::Room& room);
    void update_time(const Instant& time);

  private:
    static constexpr std::size_t sz{ 16 };
    using Container = std::array<std::unique_ptr<Event>, sz>;

    Container           events{};
    Container::iterator next{ std::begin(events) };
  };

} // namespace Timing

#endif // EVENTLIST_H_
