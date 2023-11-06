#pragma once

#include <string_view>
#include <vector>

#include <picoPNG/src/picopng.hpp>
#include <ecs/cmp/component.hpp>

struct RenderComponent_t : public ECS::Component_t {
  explicit RenderComponent_t(ECS::EntityID_t eid)
      : Component_t(eid){};

  static ECS::ComponentTypeID_t
  getComponentTypeID() noexcept {
    return static_cast<ECS::ComponentTypeID_t>(3);
  }

  void loadFromFile(const std::string_view filename);
  void
  initSpriteFromABGRData(std::vector<unsigned char> pixels);

  uint32_t w{0}, h{0};
  std::vector<uint32_t> sprite{};
};
