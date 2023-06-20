#include "man/entitymanager.hpp"
#include <algorithm>

namespace ECS{

Entity_Manager_t::Entity_Manager_t(){
  m_Entity.reserve(kNUMINITIALENTITIES);
}

void
Entity_Manager_t::createEntity(uint32_t w, uint32_t h, uint32_t color){
  auto& e = m_Entity.emplace_back(w,h);
  std::fill(begin(e.sprite), end(e.sprite), color);
}

}
