#pragma once

#include "util/typealiases.hpp"

namespace ECS{

//Foward declaration
struct GameContext_t;

struct PhysicsSystem_t {
  explicit PhysicsSystem_t() = default;

  bool update(GameContext_t& g) const;

private: 
};

} // namespace ECS
