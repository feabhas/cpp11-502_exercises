// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <cstdint> // C99
#include <iostream>
#include <string> // std::to_string

enum class House : std::uint8_t { INVALID, A, B, C, D, E, F, G, H };

const char* HouseName = "-ABCDEFGH"; // classic C technique

using Unit = std::uint8_t; // C++11

struct Device
{
  House house;
  Unit  unit;
};

struct Lamp
{
  Device device;
  bool   state;
};

int main()
{
  // Using initialisation list
  //
  Lamp desk_lamp{ { House::A, 1 }, false };

  // Using member-by-member initialisation
  //
  Lamp bed_main{};
  bed_main.device.house = House::B;
  bed_main.device.unit  = 1;
  bed_main.state        = true;

  std::cout << "Desk lamp("
            << HouseName[static_cast<int>(desk_lamp.device.house)]
            << std::to_string(desk_lamp.device.unit) << ") is "
            << (desk_lamp.state ? "on" : "off") << '\n';

  std::cout << "Bedroom main lamp("
            << HouseName[static_cast<int>(desk_lamp.device.house)]
            << std::to_string(bed_main.device.unit) << ") is "
            << (bed_main.state ? "on" : "off") << '\n';
}
