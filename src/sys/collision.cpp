#include <sys/collision.hpp>
#include <util/gamecontext.hpp>

namespace ECS {

bool 
Collision_t::update(GameContext_t &g) const {
  for (auto &e : g.getEntites()) {
    if (e.phy && e.ren) {
      if (e.phy->x > 640 || e.phy->x + e.ren->w > 640) {
        e.phy->x -= e.phy->vx;
        e.phy->vx = -e.phy->vx;
      }
      if (e.phy->y > 360 || e.phy->y + e.ren->h > 360) {
        e.phy->y -= e.phy->vy;
        e.phy->vy = -e.phy->vy;
      }
    }
  }

  return true;
}
} // namespace ECS