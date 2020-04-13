#pragma once
#include <exception>

struct NoPathFoundException : public std::exception {
  const char* what() const noexcept;
};