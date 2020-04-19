#include "PriorityQueueFrontier.h"

bool operator>(PriorityNode a, PriorityNode b) {
  return (a.priority > b.priority) 
    || (a.priority == b.priority && a.node->getParentDirectionToMe() > b.node->getParentDirectionToMe());
}

void PriorityQueueFrontier::push(Node* node, int priority) {
  frontier.push(PriorityNode { node, priority });
}

Node* PriorityQueueFrontier::pop() {
  Node* node = frontier.top().node;
  frontier.pop();
  return node;
}

bool PriorityQueueFrontier::empty() const {
  return frontier.empty();
}