#pragma once

#include <stack>

#include "Frontier.h"
#include "Node.h"

class StackFrontier : public Frontier {
private:
  std::stack<Node*> frontier;

protected:
  void pushNode(Node* node) override;
  Node* popNode() override;

public:
  bool empty() const override;
};