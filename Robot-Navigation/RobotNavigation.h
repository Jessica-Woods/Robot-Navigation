#pragma once

#include <string>

class RobotNavigation {
public:
  std::string runFromFile(std::string filepath, std::string method);

  std::string run(std::string filename, std::string text, std::string method);
};

