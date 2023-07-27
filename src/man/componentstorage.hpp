#pragma once

#include <vector>
#include <cmp/physics.hpp>
#include <cmp/render.hpp>
#include <cmp/input.hpp>
#include <util/typealiases.hpp>

namespace ECS {
struct ComponentStorage_t {
  // ComponentStorage_t() = delete;
  explicit ComponentStorage_t(std::size_t initialsize) {
    m_physicsComponents.reserve(initialsize);
    m_renderComponents.reserve(initialsize);
    m_inputComponents.reserve(initialsize);
  }

  ComponentStorage_t(const ComponentStorage_t &) = delete;
  ComponentStorage_t(ComponentStorage_t &&) = delete;
  ComponentStorage_t &operator=(const ComponentStorage_t &) = delete;
  ComponentStorage_t &operator=(ComponentStorage_t &&) = delete;

  PhysicsComponent_t& createPhysicsComponent(EntityID_t eid);
  RenderComponent_t&  createRenderComponent (EntityID_t eid);
  InputComponent_t&   createInputComponent (EntityID_t eid);

  const std::vector<PhysicsComponent_t>& getPhysicsComponents() const { return m_physicsComponents; }
        std::vector<PhysicsComponent_t>& getPhysicsComponents()       { return m_physicsComponents; }
  
  const std::vector<RenderComponent_t>& getRenderComponents() const { return m_renderComponents; }
        std::vector<RenderComponent_t>& getRenderComponents()       { return m_renderComponents; }

  const std::vector<InputComponent_t>& getInputComponents() const { return m_inputComponents; }
        std::vector<InputComponent_t>& getInputComponents()       { return m_inputComponents; }
  
private:
  std::vector<PhysicsComponent_t> m_physicsComponents{};
  std::vector<RenderComponent_t> m_renderComponents{};
  std::vector<InputComponent_t> m_inputComponents{};
};

} // namespace ECS
