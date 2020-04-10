#include "gtest/gtest.h"

#include "../Robot-Navigation/Grid.h"

TEST(Grid, assignment_example_test) {
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

  Grid grid(file);

  std::vector<std::vector<Cell>> expected = {
    { Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::WALL , Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::GOAL , Cell::WALL , Cell::EMPTY, Cell::WALL  },
    { Cell::AGENT, Cell::EMPTY, Cell::WALL , Cell::WALL , Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::EMPTY, Cell::EMPTY },
    { Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY },
    { Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::GOAL  },
    { Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::WALL , Cell::WALL , Cell::WALL , Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::WALL , Cell::EMPTY }
  };

  EXPECT_EQ(grid.getWidth(), 11);
  EXPECT_EQ(grid.getHeight(), 5);

  for (int x = 0; x < 11; ++x) {
    for (int y = 0; y < 5; ++y) {
      EXPECT_EQ(grid.get(x, y), expected[y][x]) << "Grid position (x:" << x << ", y:" << y << ") does not match";
    }
  }
}