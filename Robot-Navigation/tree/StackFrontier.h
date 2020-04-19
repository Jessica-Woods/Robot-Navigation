#pragma once

#include <stack>

#include "Frontier.h"
#include "Node.h"

class StackFrontier {
private:
  std::stack<Node*> frontier;

public:
  void push(Node* node);
  Node* pop();
  bool empty() const;
};