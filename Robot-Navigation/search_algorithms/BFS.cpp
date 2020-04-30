#include "BFS.h"

#include "../tree/QueueFrontier.h"
#include "../tree/Visited.h"
#include "../exceptions/NoPathFoundException.h"

Tree BFS::search(Grid& grid) {
  QueueFrontier frontier;
  Visited visited;

  auto root = grid.getAgentNode();
  frontier.push(root);
  visited.add(root);

  while (!frontier.empty()) {
    auto node = frontier.pop();

    if (node->getIsGoal()) {
      return Tree(root, node);
    }

    Node* up = visited.nullIfContains(grid.getEmptyNode(node->getPosition().shift(Direction::UP)));
    Node* left = visited.nullIfContains(grid.getEmptyNode(node->getPosition().shift(Direction::LEFT)));
    Node* down = visited.nullIfContains(grid.getEmptyNode(node->getPosition().shift(Direction::DOWN)));
    Node* right = visited.nullIfContains(grid.getEmptyNode(node->getPosition().shift(Direction::RIGHT)));

    frontier.push(up);
    frontier.push(left);
    frontier.push(down);
    frontier.push(right);

    visited.add(up);
    visited.add(left);
    visited.add(down);
    visited.add(right);

    node->addChild(Direction::UP, up);
    node->addChild(Direction::LEFT, left);
    node->addChild(Direction::DOWN, down);
    node->addChild(Direction::RIGHT, right);
  }

  throw NoPathFoundException();
}