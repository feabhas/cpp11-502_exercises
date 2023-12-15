// Room.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <array>
#include <string>
#include <string_view>

namespace Home
{
  class Module;

  class Room {
  public:
    Room() = default;
    Room(std::string_view str);

    bool add(Module& module);
    void all_on();
    void all_off();
    void status() const;
    void set_name(std::string_view str);

  private:
    static constexpr std::size_t max_devices{ 4 };
    using Container = std::array<Module*, max_devices>;

    Container           devices{};
    Container::iterator next{ std::begin(devices) };

    std::string name{};
  };

} // namespace Home

#endif // ROOM_H_
