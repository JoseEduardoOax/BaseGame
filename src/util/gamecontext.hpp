#pragma once

namespace ECS{
struct GameContext_t {
  virtual ~GameContext_t() = default;
  virtual const VecEntities_t& getEntities() const = 0;
  virtual       VecEntities_t& getEntites()        = 0;
  virtual const std::vector<PhysicsComponent_t>& getPhysicsComponent() const = 0;
  virtual       std::vector<PhysicsComponent_t>& getPhysicsComponent()       = 0;
};

} //namespace ECS
