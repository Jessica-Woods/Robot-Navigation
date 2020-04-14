#pragma once
class Position {
private:
public:
  Position(int x, int y);
  const int x;
  const int y;
};

bool operator==(const Position& a, const Position& b);
bool operator<(const Position& a, const Position& b);
