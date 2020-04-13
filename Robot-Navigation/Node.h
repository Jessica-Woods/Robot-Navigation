#pragma once
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

enum class Direction { UP, DOWN, LEFT, RIGHT };

class Node;

struct Edge {
  Direction direction;
  std::unique_ptr<Node> node;

  Edge(Direction direction, Node* node);
};

class Node {
private:
  Node* parent;
  std::vector<Edge> children;
  int x;
  int y;
  bool isGoal;

public:
  Node(int x, int y, bool isGoal, Node* parent);

  bool isAncestor(Node& node);
  void addChild(Direction direction, Node* child);

  int getX() const;
  int getY() const;
  bool getIsGoal() const;

  std::string toString(int level = 0);
};

bool operator==(const Node& a, const Node& b);