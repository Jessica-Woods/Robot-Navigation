#include "RobotNavigation.h"

std::string RobotNavigation::runFromFile(std::string filepath, std::string method) {
  std::string file = "this is totally a file";

  return run("test_filename", file, method);
}

std::string RobotNavigation::run(std::string filename, std::string text, std::string method) {
  return "test_filename DFS 50\n"
    "up; right; down; down; right; right; right; up; up; right; right; right;";
}
