#include "Visited.h"

Node* Visited::add(Node* node) {
  if (node != nullptr) {
    visited.insert(node->getPosition());
  }
  return node;
}

bool Visited::contains(Node* node) {
  return visited.find(node->getPosition()) != visited.end();
}

Node* Visited::nullIfContains(Node* node) {
  if (node != nullptr) {
    if (!contains(node)) {
      return node;
    } else {
      delete node;
      return nullptr;
    }
  } else {
    return nullptr;
  }
}