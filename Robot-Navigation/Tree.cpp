#include "Tree.h"

#include <stack>

Tree::Tree(Node* root, Node* goal) {
  this->root = std::unique_ptr<Node>(root);
  this->goal = goal;
}

std::string Tree::toGoalPathString() {
  auto current = goal;
  std::string result;
  
  while (current != nullptr && current != root.get()) {
    result = to_string(current->getParentDirectionToMe()) + "; " + result;
    current = current->getParent();
  }

  return result;
}

std::string Tree::toString() {
  return root->toString();
}

int Tree::totalNodes() {
  return root.get()->totalNodes();
}
