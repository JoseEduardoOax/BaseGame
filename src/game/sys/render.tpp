#include "render.hpp"

extern "C" {
#include <tinyPTC/src/tinyptc.h>
}

#include <algorithm>

#include <ecs/cmp/entity.hpp>
#include <game/cmp/render.hpp>
#include <game/cmp/physics.hpp>

template <typename GameCTX_t>
RenderSystem_t<GameCTX_t>::RenderSystem_t(uint32_t w,
                                          uint32_t h)
    : m_w{w}, m_h{h},
      m_framebuffer{
          std::make_unique<uint32_t[]>(m_w * m_h)} {
  ptc_open("Game", w, h);
}

template <typename GameCTX_t>
RenderSystem_t<GameCTX_t>::~RenderSystem_t() {
  ptc_close();
}

template <typename GameCTX_t>
void
RenderSystem_t<GameCTX_t>::renderSpriteClipped(
    const RenderComponent_t& ren,
    const PhysicsComponent_t& phy) const{

  auto getScreenXY = [&](uint32_t x, uint32_t y) {
    return m_framebuffer.get() + y * m_w + x;
  };

  // Clipping
  uint32_t left_off{0};
  uint32_t up_off{0};

  // Drawing Coordinates and size
  uint32_t x{phy.x};
  uint32_t y{phy.y};
  uint32_t w{ren.w};
  uint32_t h{ren.h};

  // Horizontal clipping rules
  if (x > m_w) { // Left clipping
    left_off = 0 - x;
    if (left_off >= w) return; // Nothing to draw
    x = 0;
    w -= left_off;
  } else if (x + ren.w >= m_w) { // Right clipping
    uint32_t right_off = x + w - m_w;
    if (right_off >= w) return; // Nothing to draw
    w -= right_off;
  }

  // Horizontal clipping rules
  if (y > m_h) { // Left clipping
    up_off = 0 - y;
    if (up_off >= h) return; // Nothing to draw
    y = 0;
    h -= up_off;
  } else if (y + ren.h >= m_h) { // Right clipping
    uint32_t down_off = y + h - m_h;
    if (down_off >= h) return; // Nothing to draw
    h -= down_off;
  }

  // Render the entity
  auto screen = getScreenXY(x, y);
  auto sprite_it =
      begin(ren.sprite) + up_off * ren.w + left_off;

  while (h--) {
    for (uint32_t i = 0; i < w; ++i) {
      if (*sprite_it & 0xFF000000) *screen = *sprite_it;
      ++sprite_it;
      ++screen;
    }
    sprite_it += ren.w - w;
    screen += m_w - w;
  }
}

template <typename GameCTX_t>
void
RenderSystem_t<GameCTX_t>::drawAllEntities(
    const GameCTX_t& g) const {
  auto& rencmps =
      g.template getComponents<RenderComponent_t>();
  std::for_each(
      begin(rencmps), end(rencmps), [&](const auto& rc) {
        const auto* eptr =
            g.getEntityByID(rc.getEntityID());

        if (!eptr) return;

        const auto* phy = eptr->template getComponent<
            PhysicsComponent_t>();
        const auto* ren = eptr->template getComponent<
            RenderComponent_t>();

        if (!phy || !ren) return;

        renderSpriteClipped(*ren, *phy);
      });
}

template <typename GameCTX_t>
bool
RenderSystem_t<GameCTX_t>::update(
    const GameCTX_t& g) const {
  auto screen     = m_framebuffer.get();
  const auto size = m_w * m_h;

  std::fill(screen, screen + size, kR);
  drawAllEntities(g);
  ptc_update(screen);

  return !ptc_process_events();
}
