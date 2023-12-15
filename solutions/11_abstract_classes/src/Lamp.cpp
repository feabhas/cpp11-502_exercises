// Lamp.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Lamp.h"
#include <iostream>
#include <string>

using std::cout;

// -----------------------------------------------------------
// Member function definitions
//
namespace Home
{
  Lamp::Lamp(House house, Unit unit) : Module{ house, unit } {}

  void Lamp::on()
  {
    cout << "Lamp ";
    Module::switch_on();
  }

  void Lamp::off()
  {
    cout << "Lamp ";
    Module::switch_off();
  }

} // namespace Home
