extern "C" {
#include <tinyPTC/src/tinyptc.h>
}

#include <sys/render.hpp>

namespace ECS{
RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h)
: m_w{w}, m_h{h}
{
  ptc_open("Game", w, h);
}


RenderSystem_t::~RenderSystem_t(){
  ptc_close();
}
}
