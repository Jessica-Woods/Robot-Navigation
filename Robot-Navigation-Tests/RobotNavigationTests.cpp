#include "gtest/gtest.h"

#include "../Robot-Navigation/RobotNavigation.h"

TEST(RobotNavigation, find_path_with_dfs) {
  std::string file = 
    "[5,11]\n"
    "(0,1)\n"
    "(7,0) | (10,3)\n"
    "(2,0,2,2)\n"
    "(8,0,1,2)\n"
    "(10,0,1,1)\n"
    "(2,3,1,2)\n"
    "(3,4,3,1)\n"
    "(9,3,1,1)\n"
    "(8,4,2,1)\n";

  RobotNavigation program;
  std::string result = program.run("test_filename", file, "DFS");

  std::string expected = 
    "test_filename DFS 50\n"
    "up; right; down; down; right; right; right; up; up; right; right; right;";
    
  EXPECT_EQ(result, expected);
}