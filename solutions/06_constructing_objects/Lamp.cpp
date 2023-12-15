// Lamp.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Lamp.h"
#include <cassert>
#include <iostream>
#include <string>

static const char* HouseName = "-ABCDEFGH"; // classic C technique

// -----------------------------------------------------------
// Member function definitions
//
namespace Home
{
  Lamp::Lamp()
  {
    std::cout << "Lamp::Lamp()\n";
  }

  Lamp::Lamp(House house, Unit unit, bool state) :
    device{ house, unit }, state{ state }
  {
    std::cout << "Lamp::Lamp(" << HouseName[static_cast<int>(device.house)]
              << std::to_string(unit) << ")\n";
  }

  Lamp::~Lamp()
  {
    std::cout << "Lamp::~Lamp(" << HouseName[static_cast<int>(device.house)]
              << std::to_string(device.unit) << ")\n";
    off();
  }

  //--------------------------------------

  void Lamp::on()
  {
    state = true;
    print_lamp();
    std::cout << " is on" << '\n';
  }

  void Lamp::off()
  {
    state = false;
    print_lamp();
    std::cout << " is off" << '\n';
  }

  bool Lamp::is_on()
  {
    return state;
  }

  void Lamp::status()
  {
    print_lamp();
    std::cout << " is " << (state ? "on" : "off") << '\n';
  }

  void Lamp::set_id(const Device& dev)
  {
    device = dev;
  }

  Device Lamp::id()
  {
    return device;
  }

  void Lamp::print_lamp()
  {
    std::cout << "Lamp(" << HouseName[static_cast<int>(device.house)]
              << std::to_string(device.unit) << ")";
  }

  Lamp make_lamp(House house, Unit unit)
  {
    assert(unit >= Unit_min && unit <= Unit_max);
    return Lamp{ house, unit, false };
  }

} // namespace Home
