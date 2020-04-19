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

Tree RobotNavigation::runSearch(std::string method, std::vector<std::string>& lines) {
  Grid grid(Grid::fromLines(lines));
  //Tree tree(grid);

  // Uninformed
  if (method == "DFS") { return DFS::search(grid); } 
  else if (method == "BFS") { return BFS::search(grid); }

  // Informed
  else if (method == "GBFS") { return GBFS::search(grid); }
  //} else if (method == "AS") {

  //  return tree;
  //// Custom
  //} else if (method == "CUS1") {

  //  return tree;
  //} else if (method == "CUS2") {

  //  return tree;
  //} else {
  //  return tree;
  //} //throw std::runtime_error("Unknown Method: " + method); }
  else { throw std::runtime_error("Unknown Method: " + method); }
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
