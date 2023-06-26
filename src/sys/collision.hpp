#pragma once

#include "util/typealiases.hpp"

namespace ECS{

//Foward declaration
struct GameContext_t;

struct Collision_t {
  explicit Collision_t() = default;

  bool update(GameContext_t& g) const;

private: 
};

} // namespace ECS
