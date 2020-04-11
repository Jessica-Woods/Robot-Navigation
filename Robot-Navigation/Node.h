#pragma once
#include <vector>
#include <string>

class Node {
private:
  Node* parent;
  std::vector<Node*> children;
  int x;
  int y;
  bool isGoal;

public:
  Node(int x, int y, bool isGoal, Node* parent = nullptr);
  ~Node();

  bool isAncestor(Node* node);
  void addChild(Node* child);

  int getX() const;
  int getY() const;
  bool getIsGoal() const;

  std::string toString(int level = 0);
};

bool operator==(const Node& a, const Node& b);