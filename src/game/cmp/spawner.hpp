#pragma once

#include <cstdint>
#include <chrono>
#include <ecs/cmp/component.hpp>

// Literals
using namespace std::chrono_literals; // FEO!!! O

struct SpawnerComponent_t
    : public ECS::ComponentBase_t<SpawnerComponent_t> {
  using clk = std::chrono::steady_clock;

  explicit SpawnerComponent_t(ECS::EntityID_t eid)
      : ComponentBase_t(eid){};

  clk::time_point last_spawn_time{clk::now()};
  std::chrono::duration<double> spawn_interval{3s};
  std::size_t to_be_spawned{2};
};
