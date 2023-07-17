#pragma once

#include <cstdint>
#include <vector>
#include <man/componentstorage.hpp>
#include <util/typealiases.hpp>
#include <util/gamecontext.hpp>

namespace ECS {

struct Entity_Manager_t : public GameContext_t{
  static constexpr std::size_t kNUMINITIALENTITIES {1000};

  explicit Entity_Manager_t();
  void createEntity(uint32_t x, uint32_t y, std::string filename);
  const Vec_t<Entity_t>& getEntities() const override { return m_Entity; }
        Vec_t<Entity_t>& getEntites()        override { return m_Entity;}
  const std::vector<PhysicsComponent_t>& getPhysicsComponent() const override{return m_components.getPhysicsComponent();}
        std::vector<PhysicsComponent_t>& getPhysicsComponent()       override{return m_components.getPhysicsComponent();}

private:
  Vec_t<Entity_t> m_Entity{};
  ComponentStorage_t m_components{kNUMINITIALENTITIES};
};
} // namespace ECS
