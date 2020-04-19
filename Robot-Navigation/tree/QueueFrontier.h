#pragma once

#include <queue>

#include "Node.h"
#include "Frontier.h"

class QueueFrontier : public Frontier {
private:
  std::queue<Node*> frontier;  

protected:
  void pushNode(Node* node) override;
  Node* popNode() override;

public:
  bool empty() const override;
};