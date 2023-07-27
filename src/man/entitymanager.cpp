#include <man/entitymanager.hpp>
#include <cmp/physics.hpp>
#include <algorithm>
#include <string_view>

namespace ECS{

Entity_Manager_t::Entity_Manager_t(){
  m_Entity.reserve(kNUMINITIALENTITIES);
}

const Entity_t* 
Entity_Manager_t::getEntityByID(EntityID_t eid) const{
  auto it = std::find_if(m_Entity.begin(), m_Entity.end(),
    [&](const Entity_t& e){return e.getEntityID() == eid;}
  );

  return it == m_Entity.end() ? nullptr : it.base();
}

Entity_t*
Entity_Manager_t::getEntityByID(EntityID_t eid){
  auto eptr = const_cast<const Entity_Manager_t*>(this)->getEntityByID(eid);
  return const_cast<Entity_t*>(eptr);
}

Entity_t&
Entity_Manager_t::createEntity(uint32_t x, uint32_t y, const std::string_view filename){
  auto& e = m_Entity.emplace_back(); // leer filename
  auto eid = e.getEntityID();
  auto& rn = m_components.createRenderComponent(eid);
  auto& ph = m_components.createPhysicsComponent(eid);
  rn.loadFromFile(filename);
  e.phy = &ph;
  e.ren = &rn;
  ph.x = x; ph.y = y;
  
  return e;
}

void
Entity_Manager_t::addInputComponent(Entity_t& e){
  if(!e.inp){
    auto& cmp = m_components.createInputComponent(e.getEntityID());
    e.inp = &cmp;
  }
}

}
