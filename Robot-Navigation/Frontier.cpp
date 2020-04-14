#include "Frontier.h"

Frontier::Frontier(Node* node) {
  root = node;
  frontier.push_back(node);
}

Node* Frontier::push(Node* node) {
  if (node == nullptr) { return nullptr; }
  if (visited.find(node->getPosition()) != visited.end()) { return nullptr; }

  visited.insert(node->getPosition());
  frontier.push_back(node);
  return node;
}

Node* Frontier::popLastIn() {
  Node* node = frontier.back();
  frontier.pop_back();
  return node;
}

bool Frontier::empty() { 
  return frontier.empty(); 
}