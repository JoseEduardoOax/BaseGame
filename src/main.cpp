extern "C" { 
#include <tinyPTC/src/tinyptc.h>
} 

#include <sys/render.hpp>
#include <sys/physics.hpp>
#include <sys/collision.hpp>
#include <man/entitymanager.hpp>
#include <iostream>
 
constexpr uint32_t kSCRWIDTH  {640};
constexpr uint32_t kSCRHEIGHT {360};

int main() {
  try {
    ECS::Entity_Manager_t EntityMan;  
    EntityMan.createEntity(20, 40, "assets/character.png"); 
    EntityMan.createEntity(80, 10, "assets/character.png"); 
    EntityMan.createEntity(200, 70, "assets/character.png"); 
    
    const ECS::RenderSystem_t Render{kSCRWIDTH, kSCRHEIGHT}; 
    ECS::PhysicsSystem_t Physics;
    ECS::Collision_t Collision;
    
    while(Render.update(EntityMan)){
      Physics.update(EntityMan);
      Collision.update(EntityMan);
    }

  } catch (...) {
    std::cout <<"Capturada\n";
  }
  
  return 0;
}
