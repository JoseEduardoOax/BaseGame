#pragma once

#include <cstdint>
#include <memory>

#include <ecs/cmp/entity.hpp>
#include <game/cmp/render.hpp>
#include <game/cmp/physics.hpp>

template <typename GameCTX_t>
struct RenderSystem_t {
  explicit RenderSystem_t(uint32_t w, uint32_t h);
  ~RenderSystem_t();

  bool update(const GameCTX_t& g) const;
  void drawAllEntities(const GameCTX_t& g) const;
  void drawEntity(const ECS::Entity_t& e) const;

  void renderSpriteClipped(const RenderComponent_t& ren, const PhysicsComponent_t& phy) const;

  // Constantes
  static constexpr uint32_t kR = 0x000000FF;

private:
  const uint32_t m_w{0}, m_h{0};
  std::unique_ptr<uint32_t[]> m_framebuffer{nullptr};
};
