#include "Position.h"

Position::Position(int X, int Y) : x(X), y(Y){}

bool operator==(const Position& a, const Position& b) {
  return a.x == b.x && a.y == b.y;

}

bool operator<(const Position& a, const Position& b) {
  return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
