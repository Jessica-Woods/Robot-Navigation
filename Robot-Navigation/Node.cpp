#include "Node.h"
#include <sstream>

Node::Node(int x, int y, bool isGoal, Node* parent) {
  this->parent = parent;
  this->x = x;
  this->y = y;
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

int Node::getX() const { return x; }
int Node::getY() const { return y; }
bool Node::getIsGoal() const { return isGoal; }

std::string Node::toString(int level) {
  std::stringstream s;
  std::string indent(level * 2, ' ');
  s << indent << "(x: " << x << ", y: " << y << ")";
  if(isGoal) { s << " GOAL"; }
  s << "\n";

  for (auto& child : children) {
    s << child.node->toString(level + 1);
  }
  return s.str();
}

bool operator==(const Node& a, const Node& b) {
  return a.getX() == b.getX() && a.getY() == b.getY() && a.getIsGoal() == b.getIsGoal();
}

Edge::Edge(Direction dir, Node* node) : direction(dir) {
  this->node = std::unique_ptr<Node>(node);
}
