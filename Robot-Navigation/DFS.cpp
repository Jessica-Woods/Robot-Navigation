#include "DFS.h"

#include <deque>

#include "Frontier.h"
#include "NoPathFoundException.h"

Tree DFS::search(Grid& grid) {
  auto root = grid.getAgentNode();
  Frontier frontier(root);

  while (!frontier.empty()) {
    auto node = frontier.popLastIn();

    if (node->getIsGoal()) {
      return Tree(root, node);
    }

    int x = node->getX();
    int y = node->getY();

    // We want UP -> LEFT -> DOWN -> RIGHT but we insert in reverse because our 
    // DFS is implemented with a stack. 
    Node* right = frontier.push(grid.getEmptyNode(x + 1, y, node));
    Node* down = frontier.push(grid.getEmptyNode(x, y + 1, node));
    Node* left = frontier.push(grid.getEmptyNode(x - 1, y, node));
    Node* up = frontier.push(grid.getEmptyNode(x, y - 1, node));

    // We add the child nodes in the normal order so the order of children
    // matches the order of evaluation.
    node->addChild(Direction::UP, up);
    node->addChild(Direction::LEFT, left);
    node->addChild(Direction::DOWN, down);
    node->addChild(Direction::RIGHT, right);
  }

  throw NoPathFoundException();
}