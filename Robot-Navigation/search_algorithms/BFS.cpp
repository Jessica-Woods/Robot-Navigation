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

    auto directions = { Direction::UP, Direction::LEFT, Direction::DOWN, Direction::RIGHT };
    for (auto direction : directions) {
      Node* child = visited.nullIfVisitedFromShorterPath(grid.getEmptyNode(node->getPosition().shift(direction)));
      frontier.push(child);
      visited.add(child);
      node->addChild(direction, child);
    }
  }

  throw NoPathFoundException();
}