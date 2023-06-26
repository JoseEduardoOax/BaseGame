#include <sys/collision.hpp>
#include <util/gamecontext.hpp>

namespace ECS {

bool Collision_t::update(GameContext_t &g) const {
  for (auto &e : g.getEntites()) {
    if(e.x > 640 || e.x + e.w > 640) {e.x -= e.vx; e.vx = -e.vx;}
    if(e.y > 360 || e.y + e.h > 360) {e.y -= e.vy; e.vy = -e.vy;}
  }

  return true;
}
} // namespace ECS
