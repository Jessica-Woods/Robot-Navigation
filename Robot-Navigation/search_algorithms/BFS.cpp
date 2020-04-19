#include "BFS.h"

#include <deque>

#include "../tree/Frontier.h"
#include "../exceptions/NoPathFoundException.h"

Tree BFS::search(Grid& grid) {
  auto root = grid.getAgentNode();
  Frontier frontier(root);

  while (!frontier.empty()) {
    auto node = frontier.popFirstIn();

    if (node->getIsGoal()) {
      return Tree(root, node);
    }

    // We want UP -> LEFT -> DOWN -> RIGHT but we insert in reverse because our 
    // BFS is implemented with a queue.

    Node* up = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::UP)));
    Node* left = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::LEFT)));
    Node* down = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::DOWN)));
    Node* right = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::RIGHT)));

    // We add the child nodes in the normal order so the order of children
    // matches the order of evaluation.
    node->addChild(Direction::UP, up);
    node->addChild(Direction::LEFT, left);
    node->addChild(Direction::DOWN, down);
    node->addChild(Direction::RIGHT, right);
  }

  throw NoPathFoundException();
}