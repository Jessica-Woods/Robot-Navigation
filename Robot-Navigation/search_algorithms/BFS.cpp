#include "BFS.h"

#include "../tree/QueueFrontier.h"
#include "../exceptions/NoPathFoundException.h"

Tree BFS::search(Grid& grid) {
  QueueFrontier frontier;

  auto root = grid.getAgentNode();
  frontier.push(root);

  while (!frontier.empty()) {
    auto node = frontier.pop();

    if (node->getIsGoal()) {
      return Tree(root, node);
    }

    Node* up = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::UP)));
    Node* left = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::LEFT)));
    Node* down = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::DOWN)));
    Node* right = frontier.push(grid.getEmptyNode(node->getPosition().shift(Direction::RIGHT)));

    node->addChild(Direction::UP, up);
    node->addChild(Direction::LEFT, left);
    node->addChild(Direction::DOWN, down);
    node->addChild(Direction::RIGHT, right);
  }

  throw NoPathFoundException();
}