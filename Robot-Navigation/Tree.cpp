#include "Tree.h"
#include <tuple>
#include <set>

Tree::Tree(Grid &g) : grid(g) {
  int startX = grid.getAgentX();
  int startY = grid.getAgentY();
  root = expandNode(getNodeFromGrid(startX, startY, nullptr));
}

Tree::~Tree() {
  delete root;
}

std::string Tree::toString() {
  return root->toString();
}

Node* Tree::getNodeFromGrid(int x, int y, Node* parent) {
  return new Node(x, y, grid.isGoalAt(x, y), parent);
}

// Given an unexplored node with node children, expand it to include any children it should have
// based on the grid.
Node* Tree::expandNode(Node* node) {
  int x = node->getX();
  int y = node->getY();

  if (!grid.inBounds(x, y) || node->isAncestor(node)) {
    delete node;
    return nullptr;
  }

  auto cell = grid.get(x, y);
  if (cell == Cell::WALL) {
    delete node;
    return nullptr;
  }

  if (cell == Cell::GOAL) {
    return node;
  }
  
  node->addChild(expandNode(getNodeFromGrid(x    , y - 1, node))); // Up
  node->addChild(expandNode(getNodeFromGrid(x - 1, y    , node))); // Left
  node->addChild(expandNode(getNodeFromGrid(x    , y + 1, node))); // Down
  node->addChild(expandNode(getNodeFromGrid(x + 1, y    , node))); // Right

  return node;
}