// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Appliance.h"
#include "Event.h"
#include "EventList.h"
#include "Lamp.h"
#include "NamedLamp.h"
#include "Room.h"
#include <cstdint>
#include <iostream>

int main()
{
  Home::Lamp      desk_lamp{ Home::House::A, 2 };
  Home::NamedLamp standard_lamp{ Home::House::A, 3, "Standard Lamp" };
  Home::NamedLamp bedside_lamp{ Home::House::B, 1, "Bedside Lamp" };
  Home::Appliance coffee_machine{ Home::House::C, 1 };

  Home::Room lounge{ "lounge" };
  lounge.add(desk_lamp);
  lounge.add(standard_lamp);

  Home::Room bedroom{ "bedroom" };
  bedroom.add(bedside_lamp);

  Home::Room kitchen{ "kitchen" };
  kitchen.add(coffee_machine);

  Timing::EventList events{};

  events.add_event(Timing::Instant{ 00, 01 }, // lights on.
                   Timing::Instant{ 00, 10 }, // lights off.
                   lounge);

  events.add_event(Timing::Instant{ 00, 05 }, // lights on.
                   Timing::Instant{ 00, 10 }, // lights off.
                   bedroom);

  events.add_event(Timing::Instant{ 00, 03 }, // coffee machine on.
                   Timing::Instant{ 00, 10 }, // coffee machine off.
                   kitchen);

  for (std::uint8_t min{}; min < 15; ++min) {
    events.update_time(Timing::Instant{ 00, min });
    lounge.status();
    bedroom.status();
    kitchen.status();
  }
}
