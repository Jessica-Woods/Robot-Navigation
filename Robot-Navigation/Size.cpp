#include "Size.h"

Size::Size(int width, int height) {
  this->width = width;
  this->height = height;
}

bool operator==(const Size& a, const Size& b) {
  return a.width == b.width && a.height == b.height;
}
