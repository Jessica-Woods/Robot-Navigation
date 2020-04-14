#include "Position.h"
#include "NoPathFoundException.h"

Position::Position(int X, int Y) : x(X), y(Y){}

Position Position::shift(Direction direction) {
  if (direction == Direction::UP) {
    return Position(x, y - 1);
  } else if (direction == Direction::LEFT) {
    return Position(x - 1, y);
  } else if (direction == Direction::DOWN) {
    return Position(x, y + 1);
  } else if (direction == Direction::RIGHT) {
    return Position(x + 1, y);
  } else { throw std::exception("Error: position"); }
}

std::string Position::toString() {
  return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

bool operator==(const Position& a, const Position& b) {
  return a.x == b.x && a.y == b.y;

}

bool operator<(const Position& a, const Position& b) {
  return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
