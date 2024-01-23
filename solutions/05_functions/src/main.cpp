// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <cassert>
#include <cstdint> // C99
#include <iostream>
#include <string> // std::to_string

enum class House : std::uint8_t { INVALID, A, B, C, D, E, F, G, H };

const char* HouseName = "-ABCDEFGH"; // classic C technique

using Unit = std::uint8_t; // C++11
constexpr Unit Unit_min{ 1 };
constexpr Unit Unit_max{ 16 };

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

// Output a Lamp's data:
void print_lamp(const Lamp& lamp);

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

int main()
{
  Lamp desk_lamp{ { House::A, 1 }, false };
  auto lamp = make_lamp(House::A, 2);

  Lamp_on(desk_lamp);
  Lamp_on(lamp);

  Lamp_off(lamp);
  Lamp_off(desk_lamp);
}

// Output a Lamp's data:
//
void print_lamp(const Lamp& lamp)
{
  std::cout << "Lamp(" << HouseName[static_cast<int>(lamp.device.house)]
            << std::to_string(lamp.device.unit) << ")";
}
