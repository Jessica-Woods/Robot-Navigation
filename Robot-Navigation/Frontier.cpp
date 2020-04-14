#include "Frontier.h"

Frontier::Frontier(Node* node) {
  root = node;
  push(node);
}

Node* Frontier::push(Node* node) {
  if (node == nullptr) { return nullptr; }
  if (visited.find(node->getPosition()) != visited.end()) { return nullptr; }

  frontier.push_back(node);
  return node;
}

Node* Frontier::popLastIn() {
  Node* node = frontier.back();
  frontier.pop_back();
  visited.insert(node->getPosition());
  return node;
}

bool Frontier::empty() { 
  return frontier.empty(); 
}