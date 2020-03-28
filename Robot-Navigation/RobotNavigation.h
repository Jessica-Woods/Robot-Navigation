#pragma once

#include <string>
#include <vector>

class RobotNavigation {
public:
  std::string runFromFile(std::string filepath, std::string method);

  std::string run(std::string filename, std::vector<std::string> text, std::string method);
};

