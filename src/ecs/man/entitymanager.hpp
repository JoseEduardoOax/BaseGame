#pragma once

#include <cstdint>
#include <vector>
#include <string_view>
#include <ecs/man/componentstorage.hpp>
#include <ecs/cmp/entity.hpp>
#include <ecs/util/typealiases.hpp>

namespace ECS {

struct Entity_Manager_t {
  static constexpr std::size_t kNUMINITIALENTITIES{1000};

  explicit Entity_Manager_t();

  // Entity_t& createEntity(uint32_t x, uint32_t y, const
  // std::string_view filename); void
  // addInputComponent(Entity_t& e);
  //
  Entity_t& createEntity() {
    return m_Entity.emplace_back();
  }

  template <typename CMP_t>
  CMP_t& addComponent(Entity_t& e) {
    CMP_t* cmp_ptr{e.getComponent<CMP_t>()};

    if (!cmp_ptr) {
      auto& cmp = m_components.createComponent<CMP_t>(
          e.getEntityID());
      e.addComponent(cmp);
      cmp_ptr = &cmp;
    }

    return *cmp_ptr;
  }

  const Entity_t* getEntityByID(EntityID_t eid) const;
  Entity_t* getEntityByID(EntityID_t eid);

  const Vec_t<Entity_t>& getEntities() const {
    return m_Entity;
  }

  Vec_t<Entity_t>& getEntites() { return m_Entity; }

  template <typename CMP_t>
  const Vec_t<CMP_t>& getComponents() const {
    return m_components.getComponents<CMP_t>();
  }

  template <typename CMP_t>
  Vec_t<CMP_t>& getComponents() {
    return m_components.getComponents<CMP_t>();
  }

private:
  Vec_t<Entity_t> m_Entity{};
  ComponentStorage_t m_components{kNUMINITIALENTITIES};
};
} // namespace ECS
