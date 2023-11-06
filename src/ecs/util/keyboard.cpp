#include "keyboard.hpp"
#include <iterator>
#include <optional>

namespace ECS{

bool 
Keyboard_t::isKeyPressed(KeySym k) const noexcept {
  if (auto it = getIterator(k))
    return (*it)->second;

  return false;
}

void
Keyboard_t::keyPressed(KeySym k) noexcept{
  if(auto it = getIterator(k))
    (*it)->second = true;
}

void
Keyboard_t::keyReleased(KeySym k) noexcept{
  if(auto it = getIterator(k))
    (*it)->second = false;
}

const std::optional<Keyboard_t::UnorMapConstIt>
Keyboard_t::getIterator(KeySym k) const noexcept{
  auto it = m_pressedKeys.find(k);
  
  if(it != m_pressedKeys.end()){
    return it;
  }
  return {};
}

std::optional<Keyboard_t::UnorMapIt>
Keyboard_t::getIterator(KeySym k) noexcept{
  auto it = const_cast<const Keyboard_t*>(this)->getIterator(k);
  
  if(it){
    auto output = m_pressedKeys.begin();
    std::advance(output, std::distance<UnorMapConstIt>(m_pressedKeys.begin(), (*it)));
    return output;
  }

  return {};
}
}
