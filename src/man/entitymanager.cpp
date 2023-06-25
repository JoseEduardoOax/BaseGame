#include <man/entitymanager.hpp>
#include <algorithm>

namespace ECS{

Entity_Manager_t::Entity_Manager_t(){
  m_Entity.reserve(kNUMINITIALENTITIES);
}

void
Entity_Manager_t::createEntity(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color){
  auto& e = m_Entity.emplace_back("assets/character.png");
  e.x = x;
  e.y = y;
  // std::fill(e.sprite.begin(), e.sprite.end(), color);
}

}
