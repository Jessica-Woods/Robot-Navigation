#pragma once

#include <string>
#include <vector>

class RobotNavigation {
private:

public:
  void whichMethod(std::string method);
  std::string runFromFile(std::string filepath, std::string method);
  std::string run(std::string filename, std::vector<std::string> text, std::string method);
};

