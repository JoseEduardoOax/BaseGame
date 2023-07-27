#include <X11/X.h>
#include <X11/keysym.h>
#include <optional>
#include <unordered_map>

namespace ECS{
struct Keyboard_t{
  using UnorMapIt = std::unordered_map<KeySym, bool>::iterator;
  using UnorMapConstIt = std::unordered_map<KeySym, bool>::const_iterator;
  
  explicit Keyboard_t() = default;

  Keyboard_t(const Keyboard_t&)               = delete;
  Keyboard_t(Keyboard_t&&)                    = delete;
  Keyboard_t& operator=(const Keyboard_t&)    = delete;
  Keyboard_t& operator=(const Keyboard_t&&)   = delete;

  bool isKeyPressed(KeySym k) const noexcept;
  void keyPressed(KeySym k) noexcept;
  void keyReleased(KeySym k) noexcept;
    
private:
  const std::optional<UnorMapConstIt> getIterator(KeySym k) const noexcept;
        std::optional<UnorMapIt>      getIterator(KeySym k)       noexcept;

  std::unordered_map<KeySym, bool> m_pressedKeys{
      {XK_BackSpace     , false}
    , {XK_Tab           , false}
    , {XK_Linefeed      , false}
    , {XK_Clear         , false}
    , {XK_Return        , false}
    , {XK_Pause         , false}
    , {XK_Scroll_Lock   , false}
    , {XK_Sys_Req       , false}
    , {XK_Escape        , false}
    , {XK_o             , false}
    , {XK_p             , false}
    , {XK_q             , false}
    , {XK_a             , false}

  };
};
}
