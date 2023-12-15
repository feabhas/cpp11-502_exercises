// Room.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <string_view>
#include <vector>

namespace Home
{
  class Switchable;

  class Room {
  public:
    Room() { devices.reserve(4); };
    Room(std::string_view str);

    bool add(Switchable& switchable);
    void all_on();
    void all_off();
    void status();
    void set_name(std::string_view str);

  private:
    using Container = std::vector<Switchable*>;
    Container        devices{};
    std::string_view name{};
  };

} // namespace Home

#endif // ROOM_H_
