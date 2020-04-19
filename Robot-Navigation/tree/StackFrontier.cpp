#include "StackFrontier.h"

void StackFrontier::pushNode(Node* node) {
  frontier.push(node);
}

Node* StackFrontier::popNode() {
  Node* node = frontier.top();
  frontier.pop();
  return node;
}

bool StackFrontier::empty() const {
  return frontier.empty();
}