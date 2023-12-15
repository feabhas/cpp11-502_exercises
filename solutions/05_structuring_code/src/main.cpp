// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Lamp.h"
#include <array>
#include <iostream>

using Home::House;
using Home::Lamp;

constexpr unsigned size{ 8 };

void     all_lamps_on(std::array<Lamp, size>& lamps);
void     all_lamps_off(std::array<Lamp, size>& lamps);
unsigned count_lamps_on(std::array<Lamp, size>& lamps);

int main()
{
  std::array<Lamp, size> lamps{
    Lamp{ { House::A, 1 }, false }, Lamp{ { House::A, 2 }, true },
    Lamp{ { House::A, 3 }, false }, Lamp{ { House::B, 1 }, true },
    Lamp{ { House::C, 1 }, false },
  };

  std::cout << "Start: " << count_lamps_on(lamps) << " lamps on" << '\n';
  all_lamps_on(lamps);
  std::cout << "All on: " << count_lamps_on(lamps) << " lamps on" << '\n';
  all_lamps_off(lamps);
  std::cout << "All off: " << count_lamps_on(lamps) << " lamps on" << '\n';
}

//-------------------------------------------------

void all_lamps_on(std::array<Lamp, size>& lamps)
{
  for (auto& lamp : lamps) {
    if (lamp.device.house != House::INVALID) { Lamp_on(lamp); }
  }
}

void all_lamps_off(std::array<Lamp, size>& lamps)
{
  for (auto& lamp : lamps) {
    if (lamp.device.house != House::INVALID) { Lamp_off(lamp); }
  }
}

unsigned count_lamps_on(std::array<Lamp, size>& lamps)
{
  unsigned count{};
  for (auto& lamp : lamps) {
    if (lamp.device.house != House::INVALID && lamp.state) { ++count; }
  }
  return count;
}
