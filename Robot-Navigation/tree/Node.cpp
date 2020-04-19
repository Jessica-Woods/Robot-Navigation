#include "Node.h"
#include <sstream>

Node::Node(Position p, bool isGoal) : pos(p) {
  this->isGoal = isGoal;
}

bool Node::isAncestor(Node& node) {
  Node* current = parent.node;
  while (current != nullptr) {
    if(*current == node) { return true; }
    current = current->parent.node;
  }

  return false;
}

void Node::addChild(Direction direction, Node* child) {
  if (child != nullptr) {
    child->parent = ParentEdge(direction, this);
    child->distanceFromRoot = distanceFromRoot + 1;
    this->children.push_back(Edge(direction, child));
  }
}

Position Node::getPosition() const { return pos; }
Node* Node::getParent() const { return parent.node; }
Direction Node::getParentDirectionToMe() const { return parent.directionToMe; }
bool Node::getIsGoal() const { return isGoal; }
int Node::getDistanceFromRoot() const { return distanceFromRoot; }

int Node::totalNodes() {
  int result = 1;
  for (auto& child : children) {
    result += child.node->totalNodes();
  }

  return result;
}

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

ParentEdge::ParentEdge() : directionToMe(Direction::UNKNOWN), node(nullptr) {}
ParentEdge::ParentEdge(Direction dir, Node* n) : directionToMe(dir), node(n) {}
