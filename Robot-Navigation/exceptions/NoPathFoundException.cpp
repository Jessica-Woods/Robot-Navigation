#include "NoPathFoundException.h"

const char* NoPathFoundException::what() const noexcept { return "Error: No path found"; }