#include "NoPathFoundException.h"

NoPathFoundException::NoPathFoundException() : std::runtime_error("No solution found.") {}