#pragma once

#include <cstdint>
#include <vector>
#include <util/typealiases.hpp>
#include <util/gamecontext.hpp>

namespace ECS {

struct Entity_Manager_t : public GameContext_t{
  using VecEntities_t = std::vector<Entity_t>;
  static constexpr std::size_t kNUMINITIALENTITIES {1000};

  explicit Entity_Manager_t();
  void createEntity(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color);
  const VecEntities_t &getEntities() const override { return m_Entity; }
  VecEntities_t& getEntites() override { return m_Entity;}

private:
  VecEntities_t m_Entity{};
};
} // namespace ECS
