#include "IDAStar.h"

#include "../tree/StackFrontier.h"
#include "../tree/Visited.h"
#include "../exceptions/NoPathFoundException.h"

Tree IDAStar::search(Grid& grid) {

  auto root = grid.getAgentNode();
  auto maxDepth = grid.manhattanDistanceToClosestGoal(root->getPosition());

  for (; maxDepth < grid.totalCells(); ++maxDepth) {
    StackFrontier frontier;

    auto root = grid.getAgentNode();
    frontier.push(root);

    while (!frontier.empty()) {
      auto node = frontier.pop();

      if (node->getIsGoal()) {
        return Tree(root, node);
      }

      if (grid.manhattanDistanceToClosestGoal(node->getPosition()) + node->getDepth() < maxDepth) {
        Node* up = grid.getEmptyNode(node->getPosition().shift(Direction::UP));
        if (up != nullptr && node->isAncestor(*up)) { up = nullptr; }

        Node* left = grid.getEmptyNode(node->getPosition().shift(Direction::LEFT));
        if (left != nullptr && node->isAncestor(*left)) { left = nullptr; }

        Node* down = grid.getEmptyNode(node->getPosition().shift(Direction::DOWN));
        if (down != nullptr && node->isAncestor(*down)) { down = nullptr; }

        Node* right = grid.getEmptyNode(node->getPosition().shift(Direction::RIGHT));
        if (right != nullptr && node->isAncestor(*right)) { right = nullptr; }

        // We want UP -> LEFT -> DOWN -> RIGHT but we insert in reverse to the frontier because our 
        // DFS is implemented with a stack.
        frontier.push(right);
        frontier.push(down);
        frontier.push(left);
        frontier.push(up);

        // We add the child nodes in the normal order so the order of children
        // matches the order of evaluation.
        node->addChild(Direction::UP, up);
        node->addChild(Direction::LEFT, left);
        node->addChild(Direction::DOWN, down);
        node->addChild(Direction::RIGHT, right);
      }
    }
  }

  throw NoPathFoundException();
}