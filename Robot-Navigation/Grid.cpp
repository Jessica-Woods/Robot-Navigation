#include "Grid.h"
#include "util/file.h"
#include "util/string.h"
#include <iostream>

void Grid::parseGridSize(std::string line) {
  std::vector<int> gridSize = util::string::numbers(line);
  width = gridSize[1];
  height = gridSize[0];

  for (int i = 0; i < height; i++) {
    std::vector<Cell> cols;
    for (int j = 0; j < width; j++) {
      cols.push_back(Cell::EMPTY);
    }
    grid.push_back(cols);
  }
}

void Grid::parseAgent(std::string line) {
  std::vector<int> agentPos = util::string::numbers(line);
  agentX = agentPos[0];
  agentY = agentPos[1];
  grid[agentY][agentX] = Cell::AGENT;
}

void Grid::parseGoals(std::string line) {
  std::vector<std::string> goals = util::string::split(line, '|');
  for (auto goal : goals) {
    std::vector<int> goalPos = util::string::numbers(goal);
    int x = goalPos[0];
    int y = goalPos[1];
    grid[y][x] = Cell::GOAL;
  }
}

void Grid::parseWall(std::string line) {
  std::vector<int> wallPos = util::string::numbers(line);
  int x = wallPos[0];
  int y = wallPos[1];
  int wallWidth = wallPos[2];
  int wallHeight = wallPos[3];

  for (int yOffset = 0; yOffset < wallHeight; yOffset++) {
    for (int xOffset = 0; xOffset < wallWidth; xOffset++) {
      grid[y + yOffset][x + xOffset] = Cell::WALL;
    }
  }
}

Grid::Grid(const std::vector<std::string>& lines) {
  parseGridSize(lines[0]);
  parseAgent(lines[1]);
  parseGoals(lines[2]);

  for (auto it = lines.begin() + 3; it != lines.end(); ++it) {
    parseWall(*it);
  }
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

Cell Grid::get(int x, int y) { return grid.at(y).at(x); }

bool Grid::inBounds(int x, int y) {
  return x >= 0 && x < width && y >= 0 && y < height;
}
bool Grid::isGoalAt(int x, int y) { return inBounds(x, y) && get(x, y) == Cell::GOAL; }

int Grid::getWidth() { return width; }
int Grid::getHeight() { return height; }
int Grid::getAgentX() { return agentX; }
int Grid::getAgentY() { return agentY; }

Node* Grid::getEmptyNode(int x, int y, Node* parent) {
  if (inBounds(x, y) && get(x, y) != Cell::WALL) {
    return new Node(x, y, isGoalAt(x, y), parent);
  }
  return nullptr;
}

Node* Grid::getAgentNode() {
  return getEmptyNode(agentX, agentY, nullptr);
}