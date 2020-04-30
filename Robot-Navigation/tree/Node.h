#pragma once
#include <vector>
#include <string>
#include <memory>

#include "../grid/Position.h"
#include "../grid/Direction.h"

class Node;

struct Edge {
  Direction direction;
  std::unique_ptr<Node> node;

  Edge(Direction direction, Node* node);
};

struct ParentEdge {
  Direction directionToMe;
  Node* node;

  ParentEdge();
  ParentEdge(Direction direction, Node* node);
};

class Node {
private:
  ParentEdge parent;
  std::vector<Edge> children;
  Position pos;
  bool isGoal;
  int depth = 0;

public:
  Node(Position pos, bool isGoal);
  ~Node();

  bool isAncestor(Node& node);
  void addChild(Direction direction, Node* child);

  Position getPosition() const;
  Node* getParent() const;
  Direction getParentDirectionToMe() const;
  bool getIsGoal() const;
  int getDepth() const;

  int totalNodes();
  std::string toString(int level = 0);
};

bool operator==(const Node& a, const Node& b);