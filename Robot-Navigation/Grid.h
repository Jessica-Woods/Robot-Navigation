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
  Position agentPos;

  void validate();

  void parseGridSize(std::string line);
  void parseAgent(std::string line);
  void parseGoals(std::string line);
  void parseWall(std::string line);
  
public:
  Grid(int width, int height, Position agentPos);
  Grid(const std::vector<std::string>& lines);

  Grid& addGoal(Position goal);
  Grid& addWall(Position wall, int width = 1, int height = 1);

  std::string toString();
  Cell get(int x, int y);
  bool inBounds(int x, int y);
  bool isGoalAt(int x, int y);

  int getWidth();
  int getHeight();
  Position getAgentPos();

  Node* getEmptyNode(Position pos);
  Node* getAgentNode();
};

