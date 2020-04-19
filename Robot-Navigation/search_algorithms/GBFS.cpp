#include "GBFS.h"

#include "../tree/PriorityQueueFrontier.h"
#include "../tree/Visited.h"
#include "../exceptions/NoPathFoundException.h"

Tree GBFS::search(Grid& grid) {
  PriorityQueueFrontier frontier;
  Visited visited;

  auto root = grid.getAgentNode();
  frontier.push(root, grid.manhattanDistanceToClosestGoal(root->getPosition()));

  while (!frontier.empty()) {
    auto node = visited.add(frontier.pop());

    if (node->getIsGoal()) {
      return Tree(root, node);
    }

    std::vector<Direction> directions = { Direction::UP, Direction::LEFT, Direction::DOWN, Direction::RIGHT };
    for(auto direction : directions) {
      auto childPosition = node->getPosition().shift(direction);
      Node* child = visited.nullIfContains(grid.getEmptyNode(childPosition));
      if(child != nullptr) {
        int priority = grid.manhattanDistanceToClosestGoal(child->getPosition());
        frontier.push(child, priority);
      }
      node->addChild(direction, child);
    }

    // We want UP -> LEFT -> DOWN -> RIGHT but we insert in reverse because our 
    // BFS is implemented with a queue.
    /*Node* up = visited.nullIfContains(grid.getEmptyNode(node->getPosition().shift(Direction::UP)));
    Node* left = visited.nullIfContains(grid.getEmptyNode(node->getPosition().shift(Direction::LEFT)));
    Node* down = visited.nullIfContains(grid.getEmptyNode(node->getPosition().shift(Direction::DOWN)));
    Node* right = visited.nullIfContains(grid.getEmptyNode(node->getPosition().shift(Direction::RIGHT)));
    
    if (up != nullptr) {
      frontier.push(up, grid.manhattanDistanceToClosestGoal(up->getPosition()));
    }

    if (up != nullptr) {
    frontier.push(left);
    frontier.push(down);
    frontier.push(right);

    // We add the child nodes in the normal order so the order of children
    // matches the order of evaluation.
    node->addChild(Direction::UP, up);
    node->addChild(Direction::LEFT, left);
    node->addChild(Direction::DOWN, down);

    node->addChild(Direction::RIGHT, right);*/
  }

  throw NoPathFoundException();
}