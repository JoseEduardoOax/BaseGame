#pragma once

#include <picoPNG/src/picopng.hpp>
#include <string_view>
#include <vector>

#include <ecs/cmp/component.hpp>

struct RenderComponent_t
    : public ECS::ComponentBase_t<RenderComponent_t> {
  explicit RenderComponent_t(ECS::EntityID_t eid)
      : ComponentBase_t(eid){};

  void loadFromFile(const std::string_view filename);
  void
  initSpriteFromABGRData(std::vector<unsigned char> pixels);

  uint32_t w{0}, h{0};
  std::vector<uint32_t> sprite{};
};
