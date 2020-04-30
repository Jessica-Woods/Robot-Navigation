#pragma once
#include <stdexcept>

struct InvalidSearchMethodException : public std::runtime_error {
  InvalidSearchMethodException(std::string method);
};
