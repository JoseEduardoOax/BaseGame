#include <man/componentstorage.hpp>

namespace ECS{
PhysicsComponent_t&
ComponentStorage_t::createPhysicsComponent(EntityID_t eid){
  auto& cmp = m_physicsComponent.emplace_back(eid);
  return cmp;
}
}
