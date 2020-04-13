#pragma once
#include <vector>
#include <string>
#include <tuple>

#include "Node.h"

enum class Cell { AGENT, GOAL, WALL, EMPTY };

class Grid {
private:
  std::vector <std::vector<Cell>> grid;
  int width;
  int height;
  int agentX;
  int agentY;

  void parseGridSize(std::string line);
  void parseAgent(std::string line);
  void parseGoals(std::string line);
  void parseWall(std::string line);
  
public:
  Grid(const std::vector<std::string>& lines);
  std::string toString();
  Cell get(int x, int y);
  bool inBounds(int x, int y);
  bool isGoalAt(int x, int y);

  int getWidth();
  int getHeight();
  int getAgentX();
  int getAgentY();

  Node* getNode(int x, int y, Node* parent);

};

