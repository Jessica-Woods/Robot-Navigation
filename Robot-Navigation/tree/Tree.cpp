#include "Tree.h"

Tree::Tree(Node* root, Node* goal) {
  this->root = std::unique_ptr<Node>(root);
  this->goal = goal;
}

std::vector<Direction> Tree::goalPath() {
  std::vector<Direction> goals;
  auto current = goal;

  while (current != nullptr && current != root.get()) {
    goals.push_back(current->getParentDirectionToMe());
    current = current->getParent();
  }

  std::reverse(goals.begin(), goals.end());
  return goals;
}

std::string Tree::toGoalPathString() {
  std::string result;

  auto vectorPath = goalPath();
  for (auto path : vectorPath) {
    result += to_string(path) + "; ";
  }

  return result;
}

std::string Tree::toString() {
  return root->toString();
}

int Tree::totalNodes() {
  return root.get()->totalNodes();
}
