#pragma once

struct Size {
  int width;
  int height;

  Size(int width, int height);
};

bool operator==(const Size& a, const Size& b);