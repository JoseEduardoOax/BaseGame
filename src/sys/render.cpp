#include <cstdint>
extern "C" {
  #include <tinyPTC/src/tinyptc.h>
}

#include <algorithm>
#include <memory>
#include <sys/render.hpp>
#include <man/entitymanager.hpp>

namespace ECS{
RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h, Entity_Manager_t& em)
  : m_w{w}, m_h{h}
  , m_framebuffer{std::make_unique<uint32_t[]>(m_w*m_h)}
  , m_EntMan{em} 
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
RenderSystem_t::drawAllEntities() const{
  auto &entities { m_EntMan.getEntities() };

  struct A{
    A(const std::unique_ptr<uint32_t[]>& f,
      const uint32_t& w):
      m_framebuffer(f), m_w(w)
    {}
    
    void operator()(const Entity_t &e) const {
      auto screen = m_framebuffer.get();
      screen += e.y * m_w + e.x;
      auto sprite_it = begin(e.sprite);
      for (uint32_t y = 0; y < e.h; ++y) {
        std::copy(sprite_it, sprite_it + e.w, screen);
        sprite_it += e.w;
        screen += m_w;
      }
    };

    const std::unique_ptr<uint32_t[]>& m_framebuffer;
    const uint32_t& m_w;
  };

  A drawEntity(m_framebuffer, m_w);
  
  std::for_each(begin(entities), end(entities), drawEntity);
 }

bool
RenderSystem_t::update() const{
  auto screen = m_framebuffer.get();
  const auto size = m_w*m_h;

  std::fill(screen, screen+size, kR);
  drawAllEntities();
  ptc_update(screen);
  
  return !ptc_process_events();
}
}
