// Room.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Room.h"
#include "Lamp.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>

static bool check_on(const Home::Switchable* switchable)
{
  return switchable->is_on();
}

namespace Home
{
  Room::Room(std::string_view str) : devices{}, name{ str } {}

  bool Room::add(Switchable& switchable)
  {
    devices.push_back(&switchable);
    return true;
  }

  void Room::all_on()
  {
    for (auto device : devices) {
      device->on();
    }
  }

  void Room::all_off()
  {
    for (auto device : devices) {
      device->off();
    }
  }

  void Room::status()
  {
    if (!name.empty()) { std::cout << "In the " << name << " "; }

    auto on = std::count_if(std::begin(devices), std::end(devices), check_on);

    std::cout << "there are " << on << " devices on and "
              << devices.size() - static_cast<std::size_t>(on) << " devices off\n";
  }

  void Room::set_name(std::string_view str)
  {
    name = str;
  }

} // namespace Home
