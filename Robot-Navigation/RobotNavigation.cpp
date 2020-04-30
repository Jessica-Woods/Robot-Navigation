#include "RobotNavigation.h"

#include <iostream>
#include <stdexcept>
#include <memory>
#include <string>
#include <sstream>

#include "util/file.h"
#include "util/string.h"
#include "grid/Grid.h"
#include "tree/Tree.h"
#include "search_algorithms/DFS.h"
#include "search_algorithms/BFS.h"
#include "search_algorithms/GBFS.h"
#include "search_algorithms/AStar.h"
#include "search_algorithms/IDDFS.h"
#include "search_algorithms/IDAStar.h"
#include "exceptions/InvalidSearchMethodException.h"

Tree RobotNavigation::runSearch(std::string method, std::vector<std::string>& lines) {
  Grid grid(Grid::fromLines(lines));

  // Uninformed methods
  if (method == "DFS") { return DFS::search(grid); } 
  else if (method == "BFS") { return BFS::search(grid); }

  // Informed method
  else if (method == "GBFS") { return GBFS::search(grid); }
  else if (method == "AS") { return AStar::search(grid); }

  // Custom 1 - Iterative Deepening Depth First Search - uninformed method 
  else if (method == "CUS1") {return IDDFS::search(grid);}

  // Custom 2 - Iterative Deepening A* Search - informed method
  else if (method == "CUS2") { return IDAStar::search(grid); }

  else { throw InvalidSearchMethodException(method); }

}

std::string RobotNavigation::runFromFile(std::string filepath, std::string method) {
  std::vector<std::string> lines = util::file::readCleanLines(filepath);
  return run(filepath, lines, method);
}

std::string RobotNavigation::run(std::string filename, std::vector<std::string> lines, std::string method) {
  auto tree = runSearch(method, lines);
  std::stringstream s;
  s << filename << " " << method << " " << std::to_string(tree.totalNodes()) << std::endl;
  s << tree.toGoalPathString();
  
  auto result = s.str();
  util::string::trim(result);
  return result;
}
