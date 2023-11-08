#pragma once

#include <game/cmp/collider.hpp>
#include <game/cmp/physics.hpp>

// Forward declaration
struct ColliderComponent_t;

template <typename GameCTX_t>
struct CollisionSystem_t {
  explicit CollisionSystem_t(uint32_t w, uint32_t h);

  bool update(GameCTX_t& g) const;
  PhysicsComponent_t*
  getRequiredComponent(GameCTX_t& g,
                       const ColliderComponent_t& col) const;

private:
  const uint32_t m_w {0}, m_h {0};
};
