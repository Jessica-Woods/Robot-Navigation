#pragma once

#include <map>

#include "Node.h"
#include "../grid/Position.h"

class Visited {
private:
  std::map<Position, int> visited;

public:
  Node* add(Node* node, int cost = 0);

  // Return true if we have already visited this node
  // from a lower cost path.
  bool containsShorterPath(Node* node, int cost = 0);

  // Return nullptr if we have visited this node from a lower cost path, otherwise return the node.
  Node* nullIfVisitedFromShorterPath(Node* node, int cost = 0);
};