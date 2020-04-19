#pragma once

#include "Position.h"
#include "Size.h"

struct Rectangle {
  Position position;
  Size size;

  Rectangle(int x, int y, int width = 1, int height = 1);
  Rectangle(Position position, Size size = Size(1, 1));
};

bool operator==(const Rectangle& a, const Rectangle& b);