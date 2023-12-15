// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Lamp.h"
#include "Room.h"
#include <cstdint>
#include <iostream>

int main()
{
  auto desk_lamp     = Home::make_lamp(Home::House::A, 2);
  auto standard_lamp = Home::make_lamp(Home::House::A, 3);
  auto bedside_lamp  = Home::make_lamp(Home::House::B, 1);

  Home::Room lounge{ "lounge" };
  lounge.status();
  lounge.add(desk_lamp);
  lounge.add(standard_lamp);

  lounge.all_on();
  lounge.status();

  lounge.all_off();
  lounge.status();

#if 0
	Home::Room bedroom { "bedroom" };
    bedroom.status();
	bedroom.add(bedside_lamp);

	bedroom.all_on();
    bedroom.status();
	bedroom.all_off();
    bedroom.status();
#endif
}
