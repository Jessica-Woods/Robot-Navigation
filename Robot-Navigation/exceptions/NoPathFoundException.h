#pragma once
#include <stdexcept>

struct NoPathFoundException : public std::runtime_error {
  NoPathFoundException();
};