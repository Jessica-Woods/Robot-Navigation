#include "Direction.h"
#include <stdexcept>

std::string to_string(Direction dir) {
  if(dir == Direction::UP) { return "up"; }
  else if(dir == Direction::DOWN) { return "down"; }
  else if(dir == Direction::LEFT) { return "left"; }
  else if(dir == Direction::RIGHT) { return "right"; }
  else { throw std::exception("Unknown direction"); }
}

std::ostream& operator<<(std::ostream& stream, const Direction& direction) {
  return stream << to_string(direction);
}
