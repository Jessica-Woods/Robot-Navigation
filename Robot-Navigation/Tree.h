#pragma once
#include "Node.h"
#include <memory>
#include <string>

class Tree {
private:
  std::unique_ptr<Node> root;
  Node* goal;

public:
  Tree(Node* root, Node* goal);
  std::string toGoalPathString();
  std::string toString();
  int totalNodes();
};