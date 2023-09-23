extern "C" { 
#include <tinyPTC/src/tinyptc.h>
} 

#include <cstdint>
#include <memory>
#include <iostream>
#include <sys/render.hpp>
#include <sys/input.tpp>
#include <sys/physics.hpp>
#include <sys/collision.hpp>
#include <man/entitymanager.hpp>
 
constexpr uint32_t kSCRWIDTH  {640};
constexpr uint32_t kSCRHEIGHT {360};

int main() {
  try {
    ECS::Entity_Manager_t EntityMan;  
    EntityMan.createEntity(20, 40, "assets/character.png"); 
    EntityMan.createEntity(80, 10, "assets/character.png"); 

    auto& e = EntityMan.createEntity(200, 70, "assets/character.png");
    EntityMan.addInputComponent(e);
    
    const ECS::RenderSystem_t Render{kSCRWIDTH, kSCRHEIGHT}; 
    ECS::PhysicsSystem_t Physics;
    ECS::Collision_t Collision;
    ECS::InputSystem_t<ECS::Entity_Manager_t> Input;
    
    while(Render.update(EntityMan)){
      Input.update(EntityMan);
      Physics.update(EntityMan);
      Collision.update(EntityMan);
    }

  } catch (...) {
    std::cout <<"Capturada\n";
  }
  
  return 0;
}
