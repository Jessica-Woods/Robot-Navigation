#include "StackFrontier.h"

void StackFrontier::push(Node* node) {
  if (node != nullptr) {
    frontier.push(node);
  }
}

Node* StackFrontier::pop() {
  Node* node = frontier.top();
  frontier.pop();
  return node;
}

bool StackFrontier::empty() const {
  return frontier.empty();
}