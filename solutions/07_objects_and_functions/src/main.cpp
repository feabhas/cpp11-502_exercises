// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Lamp.h"
#include <iostream>

using Home::Device;
using Home::House;
using Home::Lamp;
using Home::make_lamp;

#define PART_1
// #define PART_2
// #define PART_3
// #define PART_4

#ifdef PART_1
void lamp_status(Lamp lamp)
{
  std::cout << "The lamp is " << (lamp.is_on() ? "on" : "off") << '\n';
}
#endif

#ifdef PART_2
void lamp_status(Lamp* const lamp)
{
  std::cout << "The lamp is " << (lamp->is_on() ? "on" : "off") << '\n';
}
#endif

#ifdef PART_3
void lamp_status(Lamp& lamp)
{
  std::cout << "The lamp is " << (lamp.is_on() ? "on" : "off") << '\n';
}
#endif

#ifdef PART_4
void lamp_status(const Lamp& lamp)
{
  std::cout << "The lamp is " << (lamp.is_on() ? "on" : "off") << '\n';
}
#endif

int main()
{
  auto study = make_lamp(House::A, 1);

  study.on();
  lamp_status(study);

  study.off();
  lamp_status(study);
}
