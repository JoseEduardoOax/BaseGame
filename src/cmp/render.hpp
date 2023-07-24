#pragma once

#include <cmp/physics.hpp>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <functional>
#include <optional>
#include <picoPNG/src/picopng.hpp>
#include <string_view>
#include <util/typealiases.hpp>
#include <vector>

namespace ECS {

struct RenderComponent_t : Component_t {
  explicit RenderComponent_t(EntityID_t eid)
      : Component_t(eid){
        };

  void loadFromFile(const std::string_view filename);
  void initSpriteFromABGRData(std::vector<unsigned char> pixels);

  uint32_t w{0}, h{0};
  std::vector<uint32_t> sprite{};
};
} // namespace ECS
