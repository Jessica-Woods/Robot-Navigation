#include "Tree.h"


Tree::Tree(Node* root, Node* goal) {
  this->root = std::unique_ptr<Node>(root);
  this->goal = goal;
}

std::string Tree::toGoalPathString() {
  auto current = goal;
  std::string result;
  
  while (current != nullptr) {
    result = current->getPosition().toString() + "\n" + result;
    current = current->getParent();
  }

  return result;
}

std::string Tree::toString() {
  return root->toString();
}