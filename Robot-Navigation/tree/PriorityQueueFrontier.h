#pragma once

#include <queue>

#include "Node.h"
#include "Frontier.h"

struct PriorityNode {
  Node* node;
  int priority;
};

bool operator>(PriorityNode a, PriorityNode b);

// Frontier that pops nodes based on priority
//
// Nodes with a lower priority are returned first.
class PriorityQueueFrontier {
private:
  std::priority_queue<PriorityNode, std::vector<PriorityNode>, std::greater<PriorityNode>> frontier;

public:
  void push(Node* node, int priority);
  Node* pop();
  bool empty() const;
};