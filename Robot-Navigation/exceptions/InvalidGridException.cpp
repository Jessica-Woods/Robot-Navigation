#include "InvalidGridException.h"

const char* InvalidGridException::what() const noexcept { return "Error: Invalid grid"; }