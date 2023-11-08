extern "C" {
#include <tinyPTC/src/tinyptc.h>
}

#include <string_view>
#include <cstdint>
#include <memory>
#include <iostream>

#include <ecs/man/entitymanager.hpp>

#include <game/cmp/render.hpp>
#include <game/cmp/physics.hpp>
#include <game/cmp/input.hpp>
#include <game/cmp/collider.hpp>

#include <game/sys/render.tpp>
#include <game/sys/physics.tpp>
#include <game/sys/input.tpp>
#include <game/sys/collision.tpp>
#include <game/sys/spawn.tpp>

constexpr uint32_t kSCRWIDTH{640};
constexpr uint32_t kSCRHEIGHT{360};

ECS::Entity_t&
createEntity(ECS::Entity_Manager_t& EntityMan, uint32_t x,
             uint32_t y, const std::string_view filename) {
  auto& e  = EntityMan.createEntity();
  auto& rn = EntityMan.addComponent<RenderComponent_t>(e);
  auto& ph = EntityMan.addComponent<PhysicsComponent_t>(e);
  auto& cl = EntityMan.addComponent<ColliderComponent_t>(e);
  rn.loadFromFile(filename);

  ph.x = x;
  ph.y = y;

  cl.box.xLeft  = 10;
  cl.box.xRight = rn.w - 10;
  cl.box.yUp    = 10;
  cl.box.yDown  = rn.h - 10;

  return e;
}

void
createPlayer(ECS::Entity_Manager_t& EntityMan, uint32_t x,
             uint32_t y) {
  auto& e =
      createEntity(EntityMan, x, y, "assets/idle_01.png");
  EntityMan.addComponent<InputComponent_t>(e);
}

void
createBlades(ECS::Entity_Manager_t& EntityMan, uint32_t x,
             uint32_t y) {
  auto& e = createEntity(EntityMan, x, y, "assets/fire.png");
  auto* phy = e.getComponent<PhysicsComponent_t>();
  if(phy){
    phy->vx = 1; phy->vy = 1;
  }
}

void
createSpawner(ECS::Entity_Manager_t& EntityMan, uint32_t x,
              uint32_t y) {
  auto& e   = EntityMan.createEntity();
  [[maybe_unused]]auto& spw = EntityMan.addComponent<SpawnerComponent_t>(e);
  auto& phy = EntityMan.addComponent<PhysicsComponent_t>(e);
  phy.x = x; phy.y = y;
}

int
main() {
  try {
    // Systems
    const RenderSystem_t<ECS::Entity_Manager_t> Render{
        kSCRWIDTH, kSCRHEIGHT};
    PhysicsSystem_t<ECS::Entity_Manager_t> Physics;
    CollisionSystem_t<ECS::Entity_Manager_t> Collision{
        kSCRWIDTH, kSCRHEIGHT};
    InputSystem_t<ECS::Entity_Manager_t> Input;
    SpawnSystem_t<ECS::Entity_Manager_t> Spawn;

    // Entites
    ECS::Entity_Manager_t EntityMan;
    createBlades(EntityMan, 50, 20);
    createBlades(EntityMan, 5, 100);
    createSpawner(EntityMan, 200, 1);
    createPlayer(EntityMan, 1, 1);

    // Main Loop
    while (Render.update(EntityMan)) {
      Input.update(EntityMan);
      Physics.update(EntityMan);
      Collision.update(EntityMan);
      Spawn.update(EntityMan);
    }

  } catch (...) {
    std::cout << "Capturada\n";
  }

  return 0;
}
