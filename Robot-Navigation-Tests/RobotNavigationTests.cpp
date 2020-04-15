#include "gtest/gtest.h"

#include "../Robot-Navigation/RobotNavigation.h"

TEST(RobotNavigation, find_path_with_dfs) {
  std::vector<std::string> file = {
    "[5,11]",
    "(0,1)",
    "(7,0) | (10,3)",
    "(2,0,2,2)",
    "(8,0,1,2)",
    "(10,0,1,1)",
    "(2,3,1,2)",
    "(3,4,3,1)",
    "(9,3,1,1)",
    "(8,4,2,1)"
  };

  RobotNavigation program;
  std::string result = program.run("test_filename", file, "DFS");

  std::string expected = 
    "test_filename DFS 41\n"
    "up; right; down; down; right; right; down; right; up; up; up; right; down; down; down; right; up; up; up; right;";
  EXPECT_EQ(result, expected);
}