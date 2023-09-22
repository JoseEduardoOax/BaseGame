#include <man/componentstorage.hpp>

namespace ECS{
PhysicsComponent_t&
ComponentStorage_t::createPhysicsComponent(EntityID_t eid){
  return createComponent<PhysicsComponent_t>(eid);
}

RenderComponent_t&
ComponentStorage_t::createRenderComponent(EntityID_t eid){
  return createComponent<RenderComponent_t>(eid);
}

InputComponent_t&
ComponentStorage_t::createInputComponent(EntityID_t eid){
  return createComponent<InputComponent_t>(eid);
}
}

