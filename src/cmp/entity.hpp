#pragma once

#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <picoPNG/src/picopng.hpp>
#include <cmp/physics.hpp>

namespace ECS{
struct Entity_t {
  explicit Entity_t(uint32_t _w, uint32_t _h) : w{_w}, h{_h} {
    sprite.resize(w*h);
  }

  explicit Entity_t(std::string filename){
    std::vector<unsigned char>pixels{};
    unsigned long dw {0}, dh {0};
    std::ifstream file(filename, std::ios::binary);
    std::vector<unsigned char> filevec(
      std::istreambuf_iterator<char>{file},
      std::istreambuf_iterator<char>{}
    );
    
    decodePNG(pixels, dw, dh, filevec.data(), filevec.size());
    
    sprite.reserve(pixels.size()/4);

    for(auto p =pixels.begin(); p!=pixels.end(); p += 4){
      uint32_t pixel =
        static_cast<uint32_t>(*(p+0)) << 16
      | static_cast<uint32_t>(*(p+1)) << 8
      | static_cast<uint32_t>(*(p+2))
      | static_cast<uint32_t>(*(p+3)) << 24;
      sprite.push_back(pixel);
    }

    // std::memcpy(sprite.data(), pixels.data(), pixels.size());
    // sprite = std::vector<uint32_t>(pixels.begin(), pixels.end());
    w = dw; h = dh;
  }

  PhysicsComponent_t* phy{ nullptr};
  uint32_t w{0}, h{0};
  std::vector<uint32_t> sprite{};
};
}
