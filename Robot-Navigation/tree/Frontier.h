#pragma once

#include <queue>
#include <stack>
#include <set>

#include "Node.h"
#include "../grid/Position.h"

class Frontier {
private:
  std::set<Position> visited;

protected:
  virtual void pushNode(Node* node) = 0;
  virtual Node* popNode() = 0;

public:
  // Push a node into the frontier.
  //
  // Returns the node if the push was successful or nullptr if we have already
  // evaluated the node.
  Node* push(Node* node);

  Node* pop();

  virtual bool empty() const = 0;
};