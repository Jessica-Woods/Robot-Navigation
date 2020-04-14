#include "Node.h"
#include <sstream>

Node::Node(Position p, bool isGoal, Node* parent) : pos(p) {
  this->parent = parent;
  this->isGoal = isGoal;
}

bool Node::isAncestor(Node& node) {
  Node* current = parent;
  while (current != nullptr) {
    if(*current == node) { return true; }
    current = current->parent;
  }

  return false;
}

void Node::addChild(Direction direction, Node* child) {
  if (child != nullptr) {
    this->children.push_back(Edge(direction, child));
  }
}

Position Node::getPosition() const { return pos; }
bool Node::getIsGoal() const { return isGoal; }

std::string Node::toString(int level) {
  std::stringstream s;
  std::string indent(level * 2, ' ');
  s << indent << "(x: " << pos.x << ", y: " << pos.y << ")";
  if(isGoal) { s << " GOAL"; }
  s << "\n";

  for (auto& child : children) {
    s << child.node->toString(level + 1);
  }
  return s.str();
}

bool operator==(const Node& a, const Node& b) {
  return a.getPosition() == b.getPosition()
  && a.getIsGoal() == b.getIsGoal();
}

Edge::Edge(Direction dir, Node* node) : direction(dir) {
  this->node = std::unique_ptr<Node>(node);
}