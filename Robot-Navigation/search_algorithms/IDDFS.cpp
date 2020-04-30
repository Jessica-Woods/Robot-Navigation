#include "IDDFS.h"

#include "../tree/StackFrontier.h"
#include "../tree/Visited.h"
#include "../exceptions/NoPathFoundException.h"

Tree IDDFS::search(Grid& grid) {
  for (int maxDepth = 0; maxDepth < grid.totalCells(); ++maxDepth) {
    StackFrontier frontier;
    Visited visited;

    auto root = grid.getAgentNode();
    frontier.push(root);
    visited.add(root);

    while (!frontier.empty()) {
      auto node = frontier.pop();

      if (node->getIsGoal()) {
        return Tree(root, node);
      }

      if (node->getDepth() < maxDepth) {
        int childPathCost = node->getDepth() + 1;

        Node* up = visited.nullIfVisitedFromShorterPath(grid.getEmptyNode(node->getPosition().shift(Direction::UP)), childPathCost);
        Node* left = visited.nullIfVisitedFromShorterPath(grid.getEmptyNode(node->getPosition().shift(Direction::LEFT)), childPathCost);
        Node* down = visited.nullIfVisitedFromShorterPath(grid.getEmptyNode(node->getPosition().shift(Direction::DOWN)), childPathCost);
        Node* right = visited.nullIfVisitedFromShorterPath(grid.getEmptyNode(node->getPosition().shift(Direction::RIGHT)), childPathCost);

        // We want UP -> LEFT -> DOWN -> RIGHT but we insert in reverse to the frontier because we're using a stack
        frontier.push(right);
        frontier.push(down);
        frontier.push(left);
        frontier.push(up);

        visited.add(up, childPathCost);
        visited.add(left, childPathCost);
        visited.add(down, childPathCost);
        visited.add(right, childPathCost);

        node->addChild(Direction::UP, up);
        node->addChild(Direction::LEFT, left);
        node->addChild(Direction::DOWN, down);
        node->addChild(Direction::RIGHT, right);
      }
    }
  }

  throw NoPathFoundException();
}