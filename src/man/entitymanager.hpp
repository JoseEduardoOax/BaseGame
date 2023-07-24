#pragma once

#include "cmp/render.hpp"
#include <cstdint>
#include <string_view>
#include <vector>
#include <man/componentstorage.hpp>
#include <util/typealiases.hpp>
#include <util/gamecontext.hpp>

namespace ECS {

struct Entity_Manager_t : public GameContext_t{
  static constexpr std::size_t kNUMINITIALENTITIES {1000};

  explicit Entity_Manager_t();
  void createEntity(uint32_t x, uint32_t y, const std::string_view filename);
  
  const Entity_t* getEntityByID(EntityID_t eid) const override;
        Entity_t* getEntityByID(EntityID_t eid)       override;
  
  const Vec_t<Entity_t>& getEntities() const override { return m_Entity; }
        Vec_t<Entity_t>& getEntites()        override { return m_Entity;}
  
  const std::vector<PhysicsComponent_t>& getPhysicsComponents() const override{return m_components.getPhysicsComponents();}
        std::vector<PhysicsComponent_t>& getPhysicsComponents()       override{return m_components.getPhysicsComponents();}
  
  const std::vector<RenderComponent_t>& getRenderComponents()   const override{return m_components.getRenderComponents();}
        std::vector<RenderComponent_t>& getRenderComponents()         override{return m_components.getRenderComponents();}

private:
  Vec_t<Entity_t> m_Entity{};
  ComponentStorage_t m_components{kNUMINITIALENTITIES};
};
} // namespace ECS
