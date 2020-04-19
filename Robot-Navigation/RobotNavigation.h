#pragma once

#include <string>
#include <vector>
#include "tree/Tree.h"

class RobotNavigation {
private:

public:
  Tree runSearch(std::string method, std::vector<std::string>& lines);
  std::string runFromFile(std::string filepath, std::string method);
  std::string run(std::string filename, std::vector<std::string> text, std::string method);
};

