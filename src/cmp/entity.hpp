#pragma once

#include <cstdint>
#include <vector>

namespace ECS{
struct Entity_t {
  explicit Entity_t(uint32_t _w, uint32_t _h) : w{_w}, h{_h} {
    sprite.resize(w*h);
  }

  uint32_t x{0}, y{0};
  uint32_t w{0}, h{0};
  std::vector<uint32_t> sprite{};
};
}
