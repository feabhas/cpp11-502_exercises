// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <array>
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

constexpr unsigned sz{ 8 };

int main()
{
  std::array<Lamp, sz> lamps{
    Lamp{ { House::A, 1 }, false }, Lamp{ { House::A, 2 }, true },
    Lamp{ { House::A, 3 }, false }, Lamp{ { House::B, 1 }, true },
    Lamp{ { House::C, 1 }, false },
  };

  for (auto& lamp : lamps) {
    if (lamp.device.house != House::INVALID) {
      std::cout << "Lamp(" << HouseName[static_cast<int>(lamp.device.house)]
                << std::to_string(lamp.device.unit) << ")";
    }
  }
}
