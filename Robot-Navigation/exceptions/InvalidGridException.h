#pragma once
#include <stdexcept>

struct InvalidGridException : public std::runtime_error {
  InvalidGridException();
};
