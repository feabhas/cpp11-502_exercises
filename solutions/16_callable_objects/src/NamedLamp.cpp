// NamedLamp.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "NamedLamp.h"
#include <iostream>

namespace Home
{
  void NamedLamp::on()
  {
    std::cout << name << ": ";
    Lamp::on();
  }

  void NamedLamp::off()
  {
    std::cout << name << ": ";
    Lamp::off();
  }

} // namespace Home
