#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) : position(x, y), size(width, height) {}

Rectangle::Rectangle(Position pos, Size sz) : position(pos), size(sz) {}

bool operator==(const Rectangle& a, const Rectangle& b) {
  return a.position == b.position && a.size == b.size;
}