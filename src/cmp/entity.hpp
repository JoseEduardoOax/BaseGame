#pragma once

#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <picoPNG/src/picopng.hpp>
#include <fstream>

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
    
    sprite.resize(pixels.size()/4);
    std::memcpy(sprite.data(), pixels.data(), pixels.size());
    // sprite = std::vector<uint32_t>(pixels.begin(), pixels.end());
    w = dw; h = dh;
  }

  uint32_t x{0}, y{0};
  uint32_t w{0}, h{0};
  int32_t vx{1}, vy{1};
  std::vector<uint32_t> sprite{};
};
}
