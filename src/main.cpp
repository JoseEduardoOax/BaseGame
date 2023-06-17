extern "C" {
#include "tinyPTC/tinyptc.h"
}

#include <cstdint>

uint32_t screen[640 * 360];
uint32_t sprite[4 * 4] = {
    0x000000FF00, 0x000000FF00, 0x000000FF00, 0x000000FF00,
    0x000000FF00, 0x000000FF00, 0x000000FF00, 0x000000FF00,
    0x000000FF00, 0x000000FF00, 0x000000FF00, 0x000000FF00,
    0x000000FF00, 0x000000FF00, 0x000000FF00, 0x000000FF00,
};

int main() {
  ptc_open("window", 640, 360);

  for (;;) {
    for (uint32_t i = 0; i < 640 * 360; ++i) {
      screen[i] = 0x00FF0000;
    }

    uint32_t *pscr = screen;
    uint32_t *psp = sprite;
    for (uint32_t i = 0; i < 4; ++i) {
      for (uint32_t j = 0; j < 4; ++j) {
        *pscr = *psp;
        ++pscr;
        ++psp;
      }

      pscr += 640 - 4;
    }

    ptc_update(screen);
  }

  ptc_close();
  return 0;
}
