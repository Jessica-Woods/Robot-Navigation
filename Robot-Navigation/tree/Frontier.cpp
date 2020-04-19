#include "Frontier.h"

Node* Frontier::push(Node* node) {
  if (node == nullptr) { return nullptr; }
  if (visited.find(node->getPosition()) != visited.end()) { return nullptr; }

  pushNode(node);

  return node;
}

Node* Frontier::pop() {
  Node* node = popNode();
  visited.insert(node->getPosition());
  return node;
}