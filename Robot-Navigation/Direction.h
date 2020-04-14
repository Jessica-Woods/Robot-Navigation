#pragma once

#include <string>

enum class Direction { UP, DOWN, LEFT, RIGHT, UNKNOWN };

std::string to_string(Direction dir);