#pragma once

#include <cstdint>

// Forward declaration
struct SpawnerComponent_t;
struct PhysicsComponent_t;

template <typename GameCTX_t>
struct SpawnSystem_t {
  explicit SpawnSystem_t() = default;

  void update(GameCTX_t& g) const;
  void spawnDeVerdad( GameCTX_t& g, uint32_t x, uint32_t y) const;
  PhysicsComponent_t* getRequiredComponent(GameCTX_t& g, const SpawnerComponent_t& spw) const;

};
