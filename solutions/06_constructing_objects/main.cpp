// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Lamp.h"
#include <array>
#include <iostream>

using Home::Device;
using Home::House;
using Home::Lamp;
using Home::make_lamp;

using std::array;

int main()
{
  array<Lamp, 8> lamps{
    Lamp{ House::A, 1 }, Lamp{ House::A, 2 },    Lamp{ House::A, 3 },
    Lamp{ House::B, 1 }, make_lamp(House::C, 2),
  };

  lamps[0].on(); // Lamp::on(&lamps[0]);
  lamps[4].on();

  for (auto& lamp : lamps) {
    if (lamp.id().house != House::INVALID) { lamp.status(); }
  }
}
