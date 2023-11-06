#include <ecs/man/entitymanager.hpp>
#include <algorithm>

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

} // namespace ECS
