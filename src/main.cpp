extern "C" {
#include <tinyPTC/src/tinyptc.h>
}

#include "sys/render.hpp"
#include <iostream>

constexpr uint32_t kSCRWIDTH  {640};
constexpr uint32_t kSCRHEIGHT {360};

int main() {
  try {
    const ECS::RenderSystem_t Render{kSCRWIDTH, kSCRHEIGHT};
    while(Render.update());

  } catch (...) {
    std::cout <<"Capturada\n";
  }
  
  return 0;
}
