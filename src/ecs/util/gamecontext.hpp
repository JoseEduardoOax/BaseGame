#pragma once

#include <ecs/cmp/entity.hpp>

namespace ECS{
struct GameContext_t {
  virtual ~GameContext_t() = default;
  
  virtual const Entity_t* getEntityByID(EntityID_t eid) const = 0;
  virtual       Entity_t* getEntityByID(EntityID_t eid)       = 0;
  
  virtual const Vec_t<Entity_t>& getEntities() const = 0;
  virtual       Vec_t<Entity_t>& getEntites()        = 0;
  
  // virtual const Vec_t<PhysicsComponent_t>& getPhysicsComponents() const = 0;
  // virtual       Vec_t<PhysicsComponent_t>& getPhysicsComponents()       = 0;
  // 
  // virtual const Vec_t<RenderComponent_t>& getRenderComponents()   const = 0;
  // virtual       Vec_t<RenderComponent_t>& getRenderComponents()         = 0;
  // 
  // virtual const Vec_t<InputComponent_t>& getInputComponents()     const = 0;
  // virtual       Vec_t<InputComponent_t>& getInputComponents()           = 0;
};

} //namespace ECS
