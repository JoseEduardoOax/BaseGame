#pragma once

#include <util/typealiases.hpp>
#include <util/keyboard.hpp>

namespace ECS{

//Foward declaration
// struct GameContext_t;

template <typename GameCTX_t>
struct InputSystem_t {
  explicit InputSystem_t();

  bool update(GameCTX_t& g) const;

private: 
  static void onkeypress(KeySym k);
  static void onkeyrelease(KeySym k);
  inline static Keyboard_t ms_Keyboard{};
};

} // namespace ECS
