#include "gtest/gtest.h"

#include "../Robot-Navigation/grid/Grid.h"
#include "../Robot-Navigation/exceptions/InvalidGridException.h"

TEST(Grid, parse_assignment_example_test) {
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

  Grid grid = Grid::fromLines(file);

  std::vector<std::vector<Cell>> expected = {
    { Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::WALL , Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::GOAL , Cell::WALL , Cell::EMPTY, Cell::WALL  },
    { Cell::AGENT, Cell::EMPTY, Cell::WALL , Cell::WALL , Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::EMPTY, Cell::EMPTY },
    { Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY },
    { Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::GOAL  },
    { Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::WALL , Cell::WALL , Cell::WALL , Cell::EMPTY, Cell::EMPTY, Cell::WALL , Cell::WALL , Cell::EMPTY }
  };

  EXPECT_EQ(grid.getSize(), Size(11, 5));

  for (int x = 0; x < 11; ++x) {
    for (int y = 0; y < 5; ++y) {
      EXPECT_EQ(grid.get(x, y), expected[y][x]) << "Grid position (x:" << x << ", y:" << y << ") does not match";
    }
  }
}

TEST(Grid, should_throw_when_agent_is_replaced) {
  // [A][ ][ ]
  // [ ][ ][ ]
  // [ ][ ][G]
  Grid grid(Size(3, 3), Position(0, 0));
  EXPECT_THROW(grid.addGoal(Position(0, 0)), InvalidGridException);
}