#pragma once
#include "Node.h"
#include <memory>

class Tree {
private:
  std::unique_ptr<Node> root;
  Node* goal;
  //Node* expandNode(Node* node);

public:
  Tree(Node* root, Node* goal);
  std::string toString();
};