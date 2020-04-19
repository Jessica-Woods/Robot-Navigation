#include "Visited.h"

Node* Visited::add(Node* node) {
  visited.insert(node->getPosition());
  return node;
}

bool Visited::contains(Node* node) {
  return visited.find(node->getPosition()) != visited.end();
}

Node* Visited::nullIfContains(Node* node) {
  if (node != nullptr && !contains(node)) {
    return node;
  } else {
    return nullptr;
  }
}