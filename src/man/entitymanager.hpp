#pragma once

#include <cstdint>
#include <vector>
#include <string_view>
#include <man/componentstorage.hpp>
#include <util/typealiases.hpp>
#include <util/gamecontext.hpp>

namespace ECS {

struct Entity_Manager_t : public GameContext_t{
  static constexpr std::size_t kNUMINITIALENTITIES {1000};

  explicit Entity_Manager_t();
  Entity_t& createEntity(uint32_t x, uint32_t y, const std::string_view filename);
  void addInputComponent(Entity_t& e);
  
  const Entity_t* getEntityByID(EntityID_t eid) const override;
        Entity_t* getEntityByID(EntityID_t eid)       override;
  
  const Vec_t<Entity_t>& getEntities() const override { return m_Entity; }
        Vec_t<Entity_t>& getEntites()        override { return m_Entity;}
  
  const Vec_t<PhysicsComponent_t>& getPhysicsComponents() const override{return m_components.getPhysicsComponents();}
        Vec_t<PhysicsComponent_t>& getPhysicsComponents()       override{return m_components.getPhysicsComponents();}
  
  const Vec_t<RenderComponent_t>& getRenderComponents()   const override{return m_components.getRenderComponents();}
        Vec_t<RenderComponent_t>& getRenderComponents()         override{return m_components.getRenderComponents();}
  
  const Vec_t<InputComponent_t>& getInputComponents()     const override{return m_components.getInputComponents(); }
        Vec_t<InputComponent_t>& getInputComponents()           override{return m_components.getInputComponents(); }

private:
  Vec_t<Entity_t> m_Entity{};
  ComponentStorage_t m_components{kNUMINITIALENTITIES};
};
} // namespace ECS
