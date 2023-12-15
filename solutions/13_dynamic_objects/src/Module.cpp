// Module.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Module.h"
#include <array>
#include <iostream>

static const char* HouseName = "-ABCDEFGH"; // classic C technique

// -----------------------------------------------------------
// Member function definitions
//
namespace Home
{
  void Module::switch_on()
  {
    state = true;
    print();
    std::cout << " is on" << '\n';
  }

  void Module::switch_off()
  {
    state = false;
    print();
    std::cout << " is off" << '\n';
  }

  bool Module::is_on() const
  {
    return state;
  }

  void Module::status() const
  {
    print();
    std::cout << " is " << (state ? "on" : "off") << '\n';
  }

  void Module::set_id(const Device& dev)
  {
    device = dev;
  }

  Device Module::id() const
  {
    return device;
  }

  void Module::print() const
  {
    std::cout << HouseName[static_cast<int>(device.house)]
              << std::to_string(device.unit);
  }

} // namespace Home
