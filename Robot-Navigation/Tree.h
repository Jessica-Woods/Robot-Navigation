#pragma once
#include "Grid.h"
#include "Node.h"
#include <set>

class Tree {
private:
  Grid& grid;
  Node* root;

  Node* getNodeFromGrid(int x, int y, Node* parent);
  Node* expandNode(Node* node);

public:
  Tree(Grid &grid);
  ~Tree();

  std::string toString();
};