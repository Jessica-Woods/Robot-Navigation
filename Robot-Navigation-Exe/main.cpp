#include <iostream>

#include "../Robot-Navigation/RobotNavigation.h"

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cout << "Usage: RobotNavigation.exe <filepath> <method>" << std::endl;
    return 1;
  }

  //try {
    RobotNavigation program;
    std::string filepath(argv[1]);
    std::string method(argv[2]);

    std::cout << program.runFromFile(filepath, method) << std::endl;
  //} catch (std::exception e) {
  //  std::cerr << e.what() << std::endl;
  //}

}