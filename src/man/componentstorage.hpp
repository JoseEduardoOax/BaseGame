#pragma once

#include <vector>
#include <cmp/physics.hpp>
#include <cmp/render.hpp>
#include <cmp/input.hpp>
#include <memory>
#include <util/typealiases.hpp>

namespace ECS {

struct ComponentVectorBase_t {};

template <typename CMP_t>
struct ComponentVector_t: ComponentVectorBase_t{
  Vec_t<CMP_t> components;
};

struct ComponentStorage_t {
  // ComponentStorage_t() = delete;
  explicit ComponentStorage_t(std::size_t initialsize) : m_initialSize(initialsize) {
  }

  ComponentStorage_t(const ComponentStorage_t &) = delete;
  ComponentStorage_t(ComponentStorage_t &&) = delete;
  ComponentStorage_t &operator=(const ComponentStorage_t &) = delete;
  ComponentStorage_t &operator=(ComponentStorage_t &&) = delete;

  PhysicsComponent_t& createPhysicsComponent(EntityID_t eid);
  RenderComponent_t&  createRenderComponent (EntityID_t eid);
  InputComponent_t&   createInputComponent (EntityID_t eid);

  template<typename CMP_t>
  CMP_t& createComponent(EntityID_t eid){
    auto& v = getComponents<CMP_t>();
    auto& cmp = v.emplace_back(eid);
    return cmp;
  }
  
  template <typename CMP_t>
  Vec_t<CMP_t>& createComponentVector(){
    auto typeID = CMP_t::getComponentTypeID();
    auto v = std::make_unique<ComponentVector_t<CMP_t>>();
    v->components.reserve(m_initialSize);
    auto* vecptr = v.get();
    m_componentVectors[typeID] = std::move(v);
    return vecptr->components;
  }
    
  template <typename CMP_t>
  Vec_t<CMP_t>& getComponents(){
    Vec_t<CMP_t>* comvec {nullptr};
    auto typeID = CMP_t::getComponentTypeID();
    auto it = m_componentVectors.find(typeID);

    if(it != m_componentVectors.end()){
      auto* v = static_cast<ComponentVector_t<CMP_t>*>(it->second.get());
      comvec = &(v->components);
    }else{
      comvec = &createComponentVector<CMP_t>();
    }

    return *comvec;
  }
  
  template <typename CMP_t>
  const Vec_t<CMP_t>& getComponents() const{
    Vec_t<CMP_t>* comvec {nullptr};
    auto typeID = CMP_t::getComponentTypeID();
    auto it = m_componentVectors.find(typeID);

    if(it != m_componentVectors.end()){
      auto* v = static_cast<ComponentVector_t<CMP_t>*>(it->second.get());
      comvec = &(v->components);
    }else{
      throw "Asi no hombre!";
      // comvec = &createComponentVector<CMP_t>();
    }

    return *comvec;
  }
  
  const std::vector<PhysicsComponent_t>& getPhysicsComponents() const { return getComponents<PhysicsComponent_t>(); }
        std::vector<PhysicsComponent_t>& getPhysicsComponents()       { return getComponents<PhysicsComponent_t>(); }
  
  const std::vector<RenderComponent_t>& getRenderComponents()   const { return getComponents<RenderComponent_t>(); }
        std::vector<RenderComponent_t>& getRenderComponents()         { return getComponents<RenderComponent_t>(); }

  const std::vector<InputComponent_t>& getInputComponents()     const { return getComponents<InputComponent_t>(); }
        std::vector<InputComponent_t>& getInputComponents()           { return getComponents<InputComponent_t>(); }
  
private:
  Hash_t<ComponentTypeID_t, Uptr<ComponentVectorBase_t>> m_componentVectors;
  std::size_t m_initialSize{100};
};

} // namespace ECS
