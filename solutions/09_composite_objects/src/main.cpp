// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Event.h"
#include "EventList.h"
#include "Lamp.h"
#include "Room.h"
#include <cstdint>
#include <iostream>

int main()
{
  Home::Lamp desk_lamp{ Home::House::A, 2 };
  Home::Lamp standard_lamp{ Home::House::A, 3 };
  Home::Lamp bedside_lamp{ Home::House::B, 1 };

  Home::Room lounge{ "lounge" };
  lounge.add(desk_lamp);
  lounge.add(standard_lamp);

  Home::Room bedroom{ "bedroom" };
  bedroom.add(bedside_lamp);

  Timing::EventList events{};

  events.add_event(Timing::Instant{ 00, 01 }, // lights on.
                   Timing::Instant{ 00, 10 }, // lights off.
                   lounge);

  events.add_event(Timing::Instant{ 00, 05 }, // lights on.
                   Timing::Instant{ 00, 10 }, // lights off.
                   bedroom);

  for (std::uint8_t min{}; min < 15; ++min) {
    events.update_time(Timing::Instant{ 00, min });
    lounge.status();
    bedroom.status();
  }
}
