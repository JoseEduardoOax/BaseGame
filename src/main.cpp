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

#include <game/sys/render.tpp>
#include <game/sys/physics.tpp>
#include <game/sys/input.tpp>
#include <game/sys/collision.tpp>

constexpr uint32_t kSCRWIDTH{640};
constexpr uint32_t kSCRHEIGHT{360};

ECS::Entity_t&
createEntity(ECS::Entity_Manager_t& EntityMan, uint32_t x,
             uint32_t y, const std::string_view filename) {
  auto& e  = EntityMan.createEntity();
  auto& rn = EntityMan.addComponent<RenderComponent_t>(e);
  auto& ph = EntityMan.addComponent<PhysicsComponent_t>(e);

  rn.loadFromFile(filename);
  ph.x = x; ph.y = y;

  return e;
}

int
main() {
  try {
    // Systems
    const RenderSystem_t<ECS::Entity_Manager_t> Render{
        kSCRWIDTH, kSCRHEIGHT};
    PhysicsSystem_t<ECS::Entity_Manager_t> Physics;
    CollisionSystem_t<ECS::Entity_Manager_t> Collision;
    InputSystem_t<ECS::Entity_Manager_t> Input;

    // Entites
    ECS::Entity_Manager_t EntityMan;
    createEntity(EntityMan, 20, 40, "assets/character.png");
    createEntity(EntityMan, 80, 10, "assets/character.png");
    auto& e = createEntity(EntityMan, 200, 70,
                           "assets/character.png");
    EntityMan.addComponent<InputComponent_t>(e);

    // Main Loop
    while (Render.update(EntityMan)) {
      Input.update(EntityMan);
      Physics.update(EntityMan);
      Collision.update(EntityMan);
    }

  } catch (...) {
    std::cout << "Capturada\n";
  }

  return 0;
}
