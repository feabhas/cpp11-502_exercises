// Appliance.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Appliance.h"
#include <iostream>

using std::cout;

namespace Home
{
  Appliance::Appliance(House house, Unit unit) : Module{ house, unit } {}

  void Appliance::on()
  {
    cout << "Appliance ";
    Module::switch_on();
  }

  void Appliance::off()
  {
    cout << "Appliance ";
    Module::switch_off();
  }

} // namespace Home
