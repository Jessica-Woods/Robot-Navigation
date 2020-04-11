#include "RobotNavigation.h"
#include "util/file.h"
#include "util/string.h"
#include "Grid.h"
#include "Tree.h"

#include <iostream>
#include <stdexcept>

void RobotNavigation::whichMethod(std::string method) {
  // Uninformed
  if (method == "DFS") {

  } else if (method == "BFS"){
  

  // Informed
  } else if (method == "GBFS") {

  } else if (method == "AS") {


  // Custom
  } else if (method == "CUS1") {

  } else if (method == "CUS2") {

  } else { throw std::runtime_error("Unknown Method: " + method); }
}

std::string RobotNavigation::runFromFile(std::string filepath, std::string method) {
  std::vector<std::string> lines = util::file::readCleanLines(filepath);
  return run(filepath, lines, method);
}

std::string RobotNavigation::run(std::string filename, std::vector<std::string> lines, std::string method) {
  std::cout << filename << std::endl;
  whichMethod(method);

  Grid grid(lines);
  Tree tree(grid);

  return tree.toString();
}
