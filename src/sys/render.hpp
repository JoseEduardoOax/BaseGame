#pragma once

#include <cstdint>

namespace ECS{

struct RenderSystem_t {
  explicit RenderSystem_t(uint32_t w, uint32_t h);
  ~RenderSystem_t();

private: 
  const uint32_t m_w{0}, m_h{0};
};

} // namespace ECS
