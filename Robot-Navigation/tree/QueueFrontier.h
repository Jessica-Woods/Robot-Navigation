#pragma once

#include <queue>

#include "Node.h"
#include "Frontier.h"

class QueueFrontier {
private:
  std::queue<Node*> frontier;  

public:
  void push(Node* node);
  Node* pop();
  bool empty() const;
};