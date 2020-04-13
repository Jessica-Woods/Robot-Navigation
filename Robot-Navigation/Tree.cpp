#include "Tree.h"

//Tree::Tree(Grid &g) : grid(g) {
//  int startX = grid.getAgentX();
//  int startY = grid.getAgentY();
//  root = std::unique_ptr<Node>(expandNode(grid.getNode(startX, startY, nullptr)));
//}

Tree::Tree(Node* root, Node* goal) {
  this->root = std::unique_ptr<Node>(root);
  this->goal = goal;
}

std::string Tree::toString() {
  return root->toString();
}

// Given an unexplored node with node children, expand it to include any children it should have
// based on the grid.
//Node* Tree::expandNode(Node* node) {
//  int x = node->getX();
//  int y = node->getY();
//
//  if (!grid.inBounds(x, y) || node->isAncestor(*node)) {
//    return nullptr;
//  }
//
//  auto cell = grid.get(x, y);
//  if (cell == Cell::WALL) {
//    return nullptr;
//  }
//
//  if (cell == Cell::GOAL) {
//    return node;
//  }
//  
//  node->addChild(Direction::UP, expandNode(grid.getNode(x    , y - 1, node)));
//  node->addChild(Direction::LEFT, expandNode(grid.getNode(x - 1, y    , node)));
//  node->addChild(Direction::DOWN, expandNode(grid.getNode(x    , y + 1, node)));
//  node->addChild(Direction::RIGHT, expandNode(grid.getNode(x + 1, y    , node)));
//
//  return node;
//}