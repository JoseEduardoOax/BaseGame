#pragma once

#include <cstdint>
#include <cmp/physics.hpp>
#include <cmp/render.hpp>
#include <cmp/input.hpp>
#include <util/typealiases.hpp>

namespace ECS {

struct Entity_t {
  explicit Entity_t() = default;

  PhysicsComponent_t*   phy{nullptr};
  RenderComponent_t*    ren{nullptr};
  InputComponent_t*     inp{nullptr};

  constexpr EntityID_t getEntityID() const noexcept { return entityID;}

private:
  EntityID_t entityID {++nextID};
  inline static EntityID_t nextID {0};
};
} // namespace ECS
