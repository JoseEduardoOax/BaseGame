#include "render.hpp"
#include "picoPNG/src/picopng.hpp"

#include <fstream>
#include <string_view>

auto
loadPNGFileIntoVector(const std::string_view filename) {
  std::vector<unsigned char> pixels{};
  unsigned long dw{0}, dh{0};
  std::ifstream file(filename.data(), std::ios::binary);
  std::vector<unsigned char> filevec(
      std::istreambuf_iterator<char>{file},
      std::istreambuf_iterator<
          char>{}); // Es EOF, como estamos leyendo un
                    // archivo su parte final es EOF

  decodePNG(pixels, dw, dh, filevec.data(), filevec.size());
  return std::tuple{dw, dh, pixels};
}

void
RenderComponent_t::initSpriteFromABGRData(
    std::vector<unsigned char> pixels) {
  sprite.reserve(pixels.size() / 4);

  for (auto p = pixels.begin(); p != pixels.end(); p += 4) {
    uint32_t pixel = static_cast<uint32_t>(*(p + 0)) << 16 |
                     static_cast<uint32_t>(*(p + 1)) << 8 |
                     static_cast<uint32_t>(*(p + 2)) |
                     static_cast<uint32_t>(*(p + 3)) << 24;
    sprite.push_back(pixel);
  }
}

void
RenderComponent_t::loadFromFile(
    const std::string_view filename) {
  auto [dw, dh, pixels] = loadPNGFileIntoVector(filename);
  w                     = dw;
  h                     = dh;
  initSpriteFromABGRData(pixels);
}
