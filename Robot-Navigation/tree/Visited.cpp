#include "Visited.h"

#include <algorithm>

Node* Visited::add(Node* node, int cost) {
  if (node != nullptr) {
    auto pos = node->getPosition();
    auto visit = visited.find(pos);
    if (visit != visited.end()) {
      int currentPathCost = visit->second;
      visited[node->getPosition()] = std::min(cost, currentPathCost);
    } else {
      visited[node->getPosition()] = cost;
    }
  }
  return node;
}

bool Visited::containsShorterPath(Node* node, int cost) {
  auto visit = visited.find(node->getPosition());
  if (visit != visited.end()) {
    return visit->second <= cost;
  } 
  return false;

  return visited.find(node->getPosition()) != visited.end();
}

Node* Visited::nullIfVisitedFromShorterPath(Node* node, int cost) {
  if (node != nullptr) {
    if (!containsShorterPath(node, cost)) {
      return node;
    } else {
      delete node;
      return nullptr;
    }
  } else {
    return nullptr;
  }
}