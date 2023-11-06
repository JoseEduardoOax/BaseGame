#pragma once

#include <cstdint>
#include <ecs/util/typealiases.hpp>

namespace ECS {

struct Component_t {
  explicit Component_t(EntityID_t eid) : entityID{eid} {}

  constexpr EntityID_t getEntityID() const noexcept {
    return entityID;
  }

private:
  ComponentID_t ComponentID{++nextID};
  EntityID_t entityID{0};
  inline static std::size_t nextID{0};
};
} // namespace ECS
