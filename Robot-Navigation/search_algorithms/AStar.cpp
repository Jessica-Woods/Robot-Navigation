#include "AStar.h"

#include "../tree/PriorityQueueFrontier.h"
#include "../tree/Visited.h"
#include "../exceptions/NoPathFoundException.h"

Tree AStar::search(Grid& grid) {
  PriorityQueueFrontier frontier;
  Visited visited;

  auto root = grid.getAgentNode();
  frontier.push(root, grid.manhattanDistanceToClosestGoal(root->getPosition()));
  visited.add(root);

  while (!frontier.empty()) {
    auto node = frontier.pop();

    if (node->getIsGoal()) {
      return Tree(root, node);
    }

    std::vector<Direction> directions = { Direction::UP, Direction::LEFT, Direction::DOWN, Direction::RIGHT };
    for(auto direction : directions) {
      auto childPosition = node->getPosition().shift(direction);
      Node* child = visited.nullIfContains(grid.getEmptyNode(childPosition));
      if(child != nullptr) {
        node->addChild(direction, child);

        int priority = grid.manhattanDistanceToClosestGoal(child->getPosition());
        frontier.push(child, priority + child->getDepth());
        visited.add(child);
      }
    }
  }

  throw NoPathFoundException();
}