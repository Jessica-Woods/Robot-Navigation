#pragma once

#include <deque>
#include <set>

#include "Node.h"
#include "Position.h"

class Frontier {
private:
  Node* root;
  std::deque<Node*> frontier;
  std::set<Position> visited;

public:
  Frontier(Node* node);
  Node* push(Node* node);
  Node* popLastIn();
  Node* popFirstIn();
  bool empty();
};

