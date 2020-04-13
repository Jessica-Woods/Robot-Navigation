#pragma once

#include <deque>

#include "Node.h"

class Frontier {
private:
  Node* root;
  std::deque<Node*> frontier;

public:
  Frontier(Node* node);
  Node* push(Node* node);
  Node* popLastIn();
  bool empty();
};

