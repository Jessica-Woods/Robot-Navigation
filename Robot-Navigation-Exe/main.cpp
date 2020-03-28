#include <iostream>

#include "../Robot-Navigation/RobotNavigation.h"

int main(int argc, char** argv) {
  RobotNavigation program;

  std::cout << program.runFromFile("test.txt", "bfs") << std::endl;
}