extern "C" { 
#include <tinyPTC/src/tinyptc.h>
} 

#include <sys/render.hpp>
#include <man/entitymanager.hpp>
#include <iostream>
 
constexpr uint32_t kSCRWIDTH  {640};
constexpr uint32_t kSCRHEIGHT {360};

int main() {
  try {
    ECS::Entity_Manager_t EntityMan;  
    EntityMan.createEntity(20, 40, 16, 16, 0x0000FF00); 
    EntityMan.createEntity(0, 0, 16, 16, 0x000000FF); 
    
    const ECS::RenderSystem_t Render{kSCRWIDTH, kSCRHEIGHT}; 
    while(Render.update(EntityMan));

  } catch (...) {
    std::cout <<"Capturada\n";
  }
  
  return 0;
}
