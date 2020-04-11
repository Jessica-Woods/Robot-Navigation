#include "Node.h"
#include <sstream>

Node::Node(int x, int y, bool isGoal, Node* parent) {
  this->parent = parent;
  this->x = x;
  this->y = y;
  this->isGoal = isGoal;
}

Node::~Node() {
  for (auto child : children) {
    delete child;
  }
}

bool Node::isAncestor(Node* node) {
  Node* current = parent;
  while (current != nullptr) {
    if(*current == *node) { return true; }
    current = current->parent;
  }

  return false;
}

void Node::addChild(Node* child) {
  if (child != nullptr) {
    this->children.push_back(child);
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

  for (auto child : children) {
    s << child->toString(level + 1);
  }

  return s.str();
}

bool operator==(const Node& a, const Node& b) {
  return a.getX() == b.getX() && a.getY() == b.getY() && a.getIsGoal() == b.getIsGoal();
}