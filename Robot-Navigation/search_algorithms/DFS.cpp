#include "DFS.h"

#include <deque>

#include "../tree/Frontier.h"
#include "../exceptions/NoPathFoundException.h"

Tree DFS::search(Grid& grid) {
  auto root = grid.getAgentNode();
  Frontier frontier(root);

  while (!frontier.empty()) {
    auto node = frontier.popLastIn();

    if (node->getIsGoal()) {
      return Tree(root, node);
    }

    // We want UP -> LEFT -> DOWN -> RIGHT but we insert in reverse because our 
    // DFS is implemented with a stack.
    Node* right = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::RIGHT)));
    Node* down = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::DOWN)));
    Node* left = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::LEFT)));
    Node* up = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::UP)));

    // We add the child nodes in the normal order so the order of children
    // matches the order of evaluation.
    node->addChild(Direction::UP, up);
    node->addChild(Direction::LEFT, left);
    node->addChild(Direction::DOWN, down);
    node->addChild(Direction::RIGHT, right);
  }

  throw NoPathFoundException();
}