#pragma once

#include <cstdint>
#include <cmp/physics.hpp>
#include <cmp/render.hpp>
#include <cmp/input.hpp>
#include <util/typealiases.hpp>

namespace ECS {

struct Entity_t {
  explicit Entity_t() = default;
  
  template <typename TYPO>
  static std::size_t getComponentTypeID(){
    static std::size_t type {++nextTypeID};
    return type;
  }
  
  template <typename CMP_t>
  void addComponent(CMP_t& c){
    auto type = getComponentTypeID<CMP_t>();
    m_components[type] = &c;
  }

  template <typename CMP_t>
  CMP_t* getComponent(){
    auto type = getComponentTypeID<CMP_t>();
    auto it = m_components.find(type);
    if(it != m_components.end()){
      return static_cast<CMP_t*>(it->second);
    }

    return nullptr;
  }

  template <typename CMP_t>
  const CMP_t* getComponent() const{
    auto p = const_cast<Entity_t*>(this)->getComponent<CMP_t>();
    return const_cast<const CMP_t*>(p);
  }
  
  constexpr EntityID_t getEntityID() const noexcept { return entityID;}
 
private:
  Hash_t<ComponentTypeID_t, Component_t*> m_components;
  inline static std::size_t nextTypeID {0};
  EntityID_t entityID {++nextID};
  inline static EntityID_t nextID {0};
};
} // namespace ECS
