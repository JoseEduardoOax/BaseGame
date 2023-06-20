extern "C" {
  #include <tinyPTC/src/tinyptc.h>
}

#include <memory>
#include <sys/render.hpp>

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
// RenderSystem_t::drawSprite(){
//     uint32_t *pscr = screen.get();
//     const uint32_t *psp = sprite;
//     for (uint32_t i = 0; i < 8; ++i) {
//       for (uint32_t j = 0; j < 8; ++j) {
//         *pscr = *psp;
//         ++pscr;
//         ++psp;
//       }
//
//       pscr += m_w - 8;
//     }
// }

bool
RenderSystem_t::update() const{
  auto screen = m_framebuffer.get();
  
  for (uint32_t i = 0; i < m_w*m_h; ++i) {
    screen[i] = kR;
  }
  ptc_update(screen);
  
  return !ptc_process_events();
}
}
