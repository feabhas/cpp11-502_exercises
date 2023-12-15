// Room.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Room.h"
#include "Lamp.h"
#include <iostream>

namespace Home
{
  Room::Room(std::string_view str) : devices{}, name{ str } {}

  bool Room::add(Lamp& lamp)
  {
    if (next == std::end(devices)) { return false; }
    *next = &lamp;
    ++next;
    return true;
  }

  void Room::all_on()
  {
    for (auto device : devices) {
      if (device) { device->on(); }
    }
  }

  void Room::all_off()
  {
    for (auto device : devices) {
      if (device) { device->off(); }
    }
  }

  void Room::status() const
  {
    if (!name.empty()) { std::cout << "In the " << name << " "; }

    unsigned on_count{};
    unsigned off_count{};
    for (auto& device : devices) {
      if (device) {
        if (device->is_on()) { ++on_count; }
        else {
          ++off_count;
        }
      }
    }

    std::cout << "there are " << on_count << " devices on and " << off_count
              << " devices off\n";
  }

  void Room::set_name(std::string_view str)
  {
    name = str;
  }

} // namespace Home
