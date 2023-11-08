#include "game/cmp/collider.hpp"
#include "game/cmp/physics.hpp"
#include "game/cmp/render.hpp"
#include "spawn.hpp"
#include <chrono>
#include <iostream>

#include <game/cmp/spawner.hpp>

template <typename GameCTX_t>
void
SpawnSystem_t<GameCTX_t>::spawnDeVerdad(
    GameCTX_t& g, uint32_t x, uint32_t y) const {
  auto& e  = g.createEntity();
  auto& rn = g.template addComponent<RenderComponent_t>(e);
  auto& ph = g.template addComponent<PhysicsComponent_t>(e);
  auto& cl = g.template addComponent<ColliderComponent_t>(e);
  rn.loadFromFile("assets/fire.png");

  ph.x = x;
  ph.y = y;

  ph.vx = 1; ph.vy = 10;

  cl.box.xLeft  = 10;
  cl.box.xRight = rn.w - 10;
  cl.box.yUp    = 10;
  cl.box.yDown  = rn.h - 10;
}

template <typename GameCTX_t>
PhysicsComponent_t*
SpawnSystem_t<GameCTX_t>::getRequiredComponent(
    GameCTX_t& g, const SpawnerComponent_t& spw) const {
  auto* e = g.getEntityByID(spw.getEntityID());

  if (e)
    return e->template getComponent<PhysicsComponent_t>();

  return nullptr;
}


template <typename GameCTX_t>
void
SpawnSystem_t<GameCTX_t>::update(GameCTX_t& g) const {
  using clk = std::chrono::steady_clock;

  auto now = clk::now();
  for (auto& spw :
       g.template getComponents<SpawnerComponent_t>()) {

    auto* phy = getRequiredComponent(g, spw);
    if (!phy) continue;

    auto passed{now - spw.last_spawn_time};
    if (spw.to_be_spawned > 0 &&
        passed > spw.spawn_interval) {
      // Spawn
      spawnDeVerdad(g, phy->x, phy->y);
      std::cout << "Spawn :) " << phy->x << " , " << phy->y << "\n";
      spw.last_spawn_time = now;
      --spw.to_be_spawned;
    }
  }
}
