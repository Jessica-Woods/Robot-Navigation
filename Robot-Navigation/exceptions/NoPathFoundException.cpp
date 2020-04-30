#include "NoPathFoundException.h"

NoPathFoundException::NoPathFoundException() : std::runtime_error("Error: No path found") {}