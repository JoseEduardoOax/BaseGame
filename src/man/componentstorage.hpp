#pragma once

#include <cmp/physics.hpp>
#include <cstddef>
#include <vector>

namespace ECS {
struct ComponentStorage_t {
  // ComponentStorage_t() = delete;
  explicit ComponentStorage_t(std::size_t initialsize) {
    m_physicsComponent.reserve(initialsize);
  }

  ComponentStorage_t(const ComponentStorage_t &) = delete;
  ComponentStorage_t(ComponentStorage_t &&) = delete;
  ComponentStorage_t &operator=(const ComponentStorage_t &) = delete;
  ComponentStorage_t &operator=(ComponentStorage_t &&) = delete;

  PhysicsComponent_t &createPhysicsComponent();

  const std::vector<PhysicsComponent_t>& getPhysicsComponent() const { return m_physicsComponent; }
        std::vector<PhysicsComponent_t>& getPhysicsComponent()       { return m_physicsComponent; }


private:
  std::vector<PhysicsComponent_t> m_physicsComponent{};
};

} // namespace ECS
