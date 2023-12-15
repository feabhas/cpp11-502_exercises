// NamedLamp.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "NamedLamp.h"
#include <iostream>

using std::cout;
using '\n';

namespace Home
{
  void NamedLamp::on()
  {
    cout << name << ": ";
    Lamp::on();
  }

  void NamedLamp::off()
  {
    cout << name << ": ";
    Lamp::off();
  }

} // namespace Home
