#include <sys/collision.hpp>
#include <util/gamecontext.hpp>

namespace ECS {

bool 
Collision_t::update(GameContext_t &g) const {
  for (auto &e : g.getEntites()) {
    auto phy = e.getComponent<PhysicsComponent_t>();
    auto ren = e.getComponent<RenderComponent_t>();
    
    if (phy && ren) {
      if (phy->x > 640 || phy->x + ren->w > 640) {
        phy->x -= phy->vx;
        phy->vx = -phy->vx;
      }
      if (phy->y > 360 || phy->y + ren->h > 360) {
        phy->y -= phy->vy;
        phy->vy = -phy->vy;
      }
    }
  }

  return true;
}
} // namespace ECS
