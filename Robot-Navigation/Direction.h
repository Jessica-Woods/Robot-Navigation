#pragma once

#include <string>
#include <ostream>

enum class Direction { UP, DOWN, LEFT, RIGHT, UNKNOWN };

std::string to_string(Direction dir);

std::ostream& operator<<(std::ostream& stream, const Direction& direction);