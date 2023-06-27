#include <man/entitymanager.hpp>
#include <cmp/physics.hpp>
#include <algorithm>

namespace ECS{

Entity_Manager_t::Entity_Manager_t(){
  m_Entity.reserve(kNUMINITIALENTITIES);
}

void
Entity_Manager_t::createEntity(uint32_t x, uint32_t y, std::string filename){
  auto& e = m_Entity.emplace_back(filename);
  auto& ph = m_components.createPhysicsComponent();
  ph.x = x; ph.y = y;

  e.phy = &ph;
  // std::fill(e.sprite.begin(), e.sprite.end(), color);
}

}
