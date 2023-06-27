#include <man/componentstorage.hpp>

namespace ECS{
PhysicsComponent_t&
ComponentStorage_t::createPhysicsComponent(){
  auto& cmp = m_physicsComponent.emplace_back();
  return cmp;
}
}
