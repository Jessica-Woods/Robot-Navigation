#pragma once

#include <set>

#include "Node.h"
#include "../grid/Position.h"

class Visited {
private:
  std::set<Position> visited;

public:
  Node* add(Node* node);

  bool contains(Node* node);

  // Return nullptr if we have visited this node, otherwise return the node.
  Node* nullIfContains(Node* node);
};