#include "RobotNavigation.h"

#include "util/file.h"

#include <iostream>

std::string RobotNavigation::runFromFile(std::string filepath, std::string method) {
  std::vector<std::string> lines = util::file::readCleanLines(filepath);
  return run(filepath, lines, method);
}

std::string RobotNavigation::run(std::string filename, std::vector<std::string> lines, std::string method) {
  std::cout << filename << std::endl;
  std::string s;
  for (auto line : lines) {
    s += line + "\n";
  }
  return s;
}
