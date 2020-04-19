#pragma once
#include <vector>
#include <string>
#include <tuple>

#include "../tree/Node.h"
#include "Position.h"
#include "Size.h"
#include "Rectangle.h"

enum class Cell { AGENT, GOAL, WALL, EMPTY };

class Grid {
private:
  std::vector<std::vector<Cell>> grid;
  Size size;
  Position agentPos;

  void validate();
public:
  Grid(Size size, Position agentPos);

  Grid& addGoal(Position goal);
  Grid& addWall(Rectangle wall);

  bool inBounds(int x, int y);
  bool isGoalAt(int x, int y);

  Cell get(int x, int y);
  Size getSize();
  Position getAgentPos();
  Node* getEmptyNode(Position pos);
  Node* getAgentNode();

  std::string toString();

  static Grid fromLines(const std::vector<std::string>& lines);
  static Size parseGridSize(std::string line);
  static Position parseAgent(std::string line);
  static std::vector<Position> parseGoals(std::string line);
  static Rectangle parseWall(std::string line);
};

