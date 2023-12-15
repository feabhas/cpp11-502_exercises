// Lamp.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Lamp.h"
#include <cassert>
#include <iostream>
#include <string>

static const char* HouseName = "-ABCDEFGH"; // classic C technique

static void print_lamp(const Home::Lamp& lamp)
{
  std::cout << "Lamp(" << HouseName[static_cast<int>(lamp.device.house)]
            << std::to_string(lamp.device.unit) << ")";
}

namespace Home
{
  void Lamp_on(Lamp& lamp)
  {
    lamp.state = true;
    print_lamp(lamp);
    std::cout << " is on" << '\n';
  }

  void Lamp_off(Lamp& lamp)
  {
    lamp.state = false;
    print_lamp(lamp);
    std::cout << " is off" << '\n';
  }

  Lamp make_lamp(House house, Unit unit)
  {
    assert(unit >= Unit_min && unit <= Unit_max);
    return Lamp{ { house, unit }, false };
  }

} // namespace Home
