#pragma once

template <typename GameCTX_t>
struct CollisionSystem_t {
  explicit CollisionSystem_t() = default;

  bool update(GameCTX_t& g) const;

private:
};
