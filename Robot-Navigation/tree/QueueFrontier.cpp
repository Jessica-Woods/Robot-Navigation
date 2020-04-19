#include "QueueFrontier.h"

void QueueFrontier::pushNode(Node* node) {
  frontier.push(node);
}

Node* QueueFrontier::popNode() {
  Node* node = frontier.front();
  frontier.pop();
  return node;
}

bool QueueFrontier::empty() const {
  return frontier.empty();
}