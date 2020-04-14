#pragma once

#include "Direction.h"

struct Position {
  int x;
  int y;

  Position(int x, int y);
  Position shift(Direction direction);
};

bool operator==(const Position& a, const Position& b);
bool operator<(const Position& a, const Position& b);
