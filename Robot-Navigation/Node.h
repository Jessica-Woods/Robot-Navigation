#pragma once
#include <vector>
#include <string>
#include <memory>
#include <map>

enum class Direction { UP, DOWN, LEFT, RIGHT };

class Node {
private:
  Node* parent;
  std::map<Direction, std::unique_ptr<Node>> children;
  int x;
  int y;
  bool isGoal;

public:
  Node(int x, int y, bool isGoal, Node* parent = nullptr);

  bool isAncestor(Node& node);
  void addChild(Direction direction, Node* child);

  int getX() const;
  int getY() const;
  bool getIsGoal() const;

  std::string toString(int level = 0);
};

bool operator==(const Node& a, const Node& b);