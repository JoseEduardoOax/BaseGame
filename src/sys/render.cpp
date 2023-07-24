extern "C" {
  #include <tinyPTC/src/tinyptc.h>
}

#include <algorithm>
#include <sys/render.hpp>
#include <util/gamecontext.hpp>

namespace ECS{
RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h)
  : m_w{w}, m_h{h}
  , m_framebuffer{std::make_unique<uint32_t[]>(m_w*m_h)}
{
  ptc_open("Game", w, h);
}

RenderSystem_t::~RenderSystem_t(){
  ptc_close();
}

void
RenderSystem_t::drawAllEntities(const GameContext_t& g) const{
  auto screen = m_framebuffer.get();

  auto getScreenXY = [&](uint32_t x, uint32_t y){
    return screen + y*m_w + x;
  };

  auto drawEntity = [&](const RenderComponent_t& rc) {
    auto eptr = g.getEntityByID(rc.getEntityID());

    if (eptr && eptr->phy) {
      auto& e = *eptr;
      auto screen = getScreenXY(e.phy->x, e.phy->y);
      auto sprite_it = begin(e.ren->sprite);
      for (uint32_t y = 0; y < e.ren->h; ++y) {
        std::copy(sprite_it, sprite_it + e.ren->w, screen);
        sprite_it += e.ren->w;
        screen += m_w;
      }
    }
  };

  auto& rencmps = g.getRenderComponents();
  std::for_each(begin(rencmps), end(rencmps), drawEntity);
 }

bool
RenderSystem_t::update(const GameContext_t& g) const{
  auto screen = m_framebuffer.get();
  g.getEntities();
  const auto size = m_w*m_h;

  std::fill(screen, screen+size, kR);
  drawAllEntities(g);
  ptc_update(screen);
  
  return !ptc_process_events();
}
}
