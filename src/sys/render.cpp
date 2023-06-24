extern "C" {
  #include <tinyPTC/src/tinyptc.h>
}

#include <algorithm>
#include <sys/render.hpp>
#include <util/gamecontext.hpp>
#include <man/entitymanager.hpp>

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

// void 
// RenderSystem_t::drawEntity(const Entity_t &e) const{
//   auto screen = m_framebuffer.get();
//   
//   screen += e.y * m_w + e.x;
//   auto sprite_it = begin(e.sprite);
//   for (uint32_t y = 0; y < e.h; ++y) {
//     std::copy(sprite_it, sprite_it + e.w, screen);
//     sprite_it += e.w;
//     screen += m_w;
//   }
// }

void
RenderSystem_t::drawAllEntities(const VecEntities_t& entities) const{
  auto screen = m_framebuffer.get();

  auto getScreenXY = [&](uint32_t x, uint32_t y){
    return screen + y*m_w + x;
  };
  
  auto drawEntity = [&](const Entity_t &e) {
    auto screen = getScreenXY(e.x, e.y);
    auto sprite_it = begin(e.sprite);
    for (uint32_t y = 0; y < e.h; ++y) {
      std::copy(sprite_it, sprite_it + e.w, screen);
      sprite_it += e.w;
      screen += m_w;
    }
  };

  std::for_each(begin(entities), end(entities), drawEntity);
 }

bool
RenderSystem_t::update(const GameContext_t& g) const{
  auto screen = m_framebuffer.get();
  g.getEntities();
  const auto size = m_w*m_h;

  std::fill(screen, screen+size, kR);
  drawAllEntities(g.getEntities());
  ptc_update(screen);
  
  return !ptc_process_events();
}
}
