#include "sys/render.hpp"
extern "C" {
#include <tinyPTC/src/tinyptc.h>
}

#include <cstdint>
#include <memory>
#include <iostream>

constexpr uint32_t kR = 0x00FF0000;
constexpr uint32_t kG = 0x0000FF00;
constexpr uint32_t kB = 0x000000FF;

constexpr uint32_t sprite[8 * 8] = {
  kG,kG,kG,kG,kG,kG,kG,kG,
  kG,kB,kR,kR,kR,kR,kB,kG,
  kG,kB,kR,kG,kG,kG,kB,kG,
  kG,kB,kB,kR,kG,kG,kB,kG,
  kG,kB,kB,kB,kR,kG,kB,kG,
  kG,kB,kB,kB,kB,kR,kB,kG,
  kG,kB,kR,kR,kR,kR,kB,kG,
  kG,kG,kG,kG,kG,kG,kG,kG,
};

constexpr uint32_t kSCRWIDTH  {640};
constexpr uint32_t kSCRHEIGHT {360};

// struct Screen_t {
//   Screen_t(uint32_t w, uint32_t h)
//   : screen(new uint32_t[w*h]){}
//
//   ~Screen_t(){
//     delete[] screen;
//   }
//   
//   uint32_t *screen {nullptr};
// };
//

void execute() {
  ptc_open("window", kSCRWIDTH, kSCRHEIGHT);

  // std::unique_ptr<uint32_t[]> screen = 
  //   std::make_unique<uint32_t[]>(kSCRHEIGHT*kSCRWIDTH);

  auto screen {std::make_unique<uint32_t[]>(kSCRWIDTH*kSCRHEIGHT)};
  
  // screen = std::move(screen2); //funcion que permite asignar otro puntero a mi puntero de forma segura

  while (!ptc_process_events()) {

    for (uint32_t i = 0; i < 640 * 360; ++i) {
      screen[i] = kR;
    }

    uint32_t *pscr = screen.get();
    const uint32_t *psp = sprite;
    for (uint32_t i = 0; i < 8; ++i) {
      for (uint32_t j = 0; j < 8; ++j) {
        *pscr = *psp;
        ++pscr;
        ++psp;
      }

      pscr += kSCRWIDTH - 8;
    }

    // throw "Excepcion";

    ptc_update(screen.get());
  }

  ptc_close();
}

int main() {
  try {
    ECS::RenderSystem_t Render{kSCRWIDTH, kSCRHEIGHT};
    // execute();

  while (!ptc_process_events()) {}
  } catch (...) {
    std::cout <<"Capturada\n";
  }
  
  return 0;
}
