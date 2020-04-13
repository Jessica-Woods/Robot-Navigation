#pragma once
#include "Grid.h"
#include "Node.h"
#include <set>
#include <memory>

class Tree {
private:
  Grid& grid;
  std::unique_ptr<Node> root;

  Node* expandNode(Node* node);

public:
  Tree(Grid &grid);

  std::string toString();
};