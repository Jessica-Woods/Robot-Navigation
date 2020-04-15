#include "Grid.h"

#include "util/file.h"
#include "util/string.h"
#include "InvalidGridException.h"

void Grid::validate() {
  if (get(agentPos.x, agentPos.y) != Cell::AGENT) {
    throw InvalidGridException();
  }
}

Grid::Grid(Size sz, Position ap) : size(sz), agentPos(ap){
  for (int i = 0; i < size.height; i++) {
    std::vector<Cell> cols;
    for (int j = 0; j < size.width; j++) {
      cols.push_back(Cell::EMPTY);
    }
    grid.push_back(cols);
  }

  grid[agentPos.y][agentPos.x] = Cell::AGENT;
}

Grid& Grid::addGoal(Position goal) {
  grid[goal.y][goal.x] = Cell::GOAL;
  validate();
  return *this;
}

Grid& Grid::addWall(Rectangle wall) {
  for (int yOffset = 0; yOffset < wall.size.height; yOffset++) {
    for (int xOffset = 0; xOffset < wall.size.width; xOffset++) {
      grid[wall.position.y + yOffset][wall.position.x + xOffset] = Cell::WALL;
    }
  }
  validate();
  return *this;
}

bool Grid::inBounds(int x, int y) {
  return x >= 0 && x < size.width && y >= 0 && y < size.height;
}
bool Grid::isGoalAt(int x, int y) { return inBounds(x, y) && get(x, y) == Cell::GOAL; }


Cell Grid::get(int x, int y) { return grid.at(y).at(x); }
Size Grid::getSize() { return size; }
Position Grid::getAgentPos() { return agentPos; }

Node* Grid::getEmptyNode(Position pos) {
  if (inBounds(pos.x, pos.y) && get(pos.x, pos.y) != Cell::WALL) {
    return new Node(Position(pos.x, pos.y), isGoalAt(pos.x, pos.y));
  }
  return nullptr;
}

Node* Grid::getAgentNode() {
  return getEmptyNode(agentPos);
}

std::string Grid::toString() {
  std::string s;
  for (auto row : grid) {
    for (auto cell : row) {
      if (cell == Cell::EMPTY) { s += "[ ]"; }
      else if (cell == Cell::AGENT) { s += "[A]"; }
      else if (cell == Cell::GOAL) { s += "[G]"; }
      else if (cell == Cell::WALL) { s += "[X]"; }
    }
    s += "\n";
  }

  return s;
}

Grid Grid::fromLines(const std::vector<std::string>& lines) {
  Size gridSize = parseGridSize(lines[0]);
  Position agentPos = parseAgent(lines[1]);

  Grid grid(gridSize, agentPos);

  std::vector<Position> goals = parseGoals(lines[2]);
  for (auto goal : goals) {
    grid.addGoal(goal);
  }

  for (auto line = lines.begin() + 3; line != lines.end(); ++line) {
    Rectangle wall = parseWall(*line);
    grid.addWall(wall);
  }

  return grid;
}

Size Grid::parseGridSize(std::string line) {
  std::vector<int> gridSize = util::string::numbers(line);
  int width = gridSize[1];
  int height = gridSize[0];
  return Size(width, height);
}

Position Grid::parseAgent(std::string line) {
  std::vector<int> agent = util::string::numbers(line);
  int x = agent[0];
  int y = agent[1];
  return Position(x, y);
}

std::vector<Position> Grid::parseGoals(std::string line) {
  std::vector<Position> result;
  std::vector<std::string> goals = util::string::split(line, '|');
  for (auto goal : goals) {
    std::vector<int> goalPos = util::string::numbers(goal);
    int x = goalPos[0];
    int y = goalPos[1];
    result.push_back(Position(x, y));
  }
  return result;
}

Rectangle Grid::parseWall(std::string line) {
  std::vector<int> wallPos = util::string::numbers(line);
  int x = wallPos[0];
  int y = wallPos[1];
  int width = wallPos[2];
  int height = wallPos[3];
  return Rectangle(Position(x, y), Size(width, height));
}