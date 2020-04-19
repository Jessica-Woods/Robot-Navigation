#include "QueueFrontier.h"

void QueueFrontier::push(Node* node) {
  if (node != nullptr) {
    frontier.push(node);
  }
}

Node* QueueFrontier::pop() {
  Node* node = frontier.front();
  frontier.pop();
  return node;
}

bool QueueFrontier::empty() const {
  return frontier.empty();
}