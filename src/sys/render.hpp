#pragma once

#include <cstdint>
#include <memory>
#include <util/typealiases.hpp>
#include <cmp/entity.hpp>

namespace ECS{

//Foward declaration
struct Entity_Manager_t;
struct GameContext_t;

struct RenderSystem_t {
  explicit RenderSystem_t(uint32_t w, uint32_t h);
  ~RenderSystem_t();

  bool update(const GameContext_t& g) const;
  void drawEntity(const Entity_t& e) const;
  void drawAllEntities(const Vec_t<Entity_t>& entities) const;
  
  //Constantes
  static constexpr uint32_t kR = 0x00FF0000;
  static constexpr uint32_t kG = 0x0000FF00;
  static constexpr uint32_t kB = 0x000000FF;

  static constexpr uint32_t sprite[8 * 8] = {
    kG,kG,kG,kG,kG,kG,kG,kG,
    kG,kB,kR,kR,kR,kR,kB,kG,
    kG,kB,kR,kG,kG,kG,kB,kG,
    kG,kB,kB,kR,kG,kG,kB,kG,
    kG,kB,kB,kB,kR,kG,kB,kG,
    kG,kB,kB,kB,kB,kR,kB,kG,
    kG,kB,kR,kR,kR,kR,kB,kG,
    kG,kG,kG,kG,kG,kG,kG,kG,
  };

private: 
  const uint32_t m_w{0}, m_h{0};
  std::unique_ptr<uint32_t[]>m_framebuffer {nullptr};
};

} // namespace ECS
