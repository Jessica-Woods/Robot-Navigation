#include "gtest/gtest.h"

#include "../Robot-Navigation/search_algorithms/IDDFS.h"
#include "../Robot-Navigation/exceptions/NoPathFoundException.h"

#include <algorithm>
TEST(IDDFS, node_count_test) {
  // [ ][G][ ]
  // [G][A][G]
  // [ ][G][ ]
  Grid grid(Size(3, 3), Position(1, 1));
  grid
    .addGoal(Position(1, 0))
    .addGoal(Position(0, 1))
    .addGoal(Position(2, 1))
    .addGoal(Position(1, 2));

  Tree treeResult = IDDFS::search(grid);

  int result = treeResult.totalNodes();
  int expected = 5;

  EXPECT_EQ(result, expected);
}

TEST(IDDFS, bias_upwards_test) {
  // [ ][G][ ]
  // [G][A][G]
  // [ ][G][ ]
  Grid grid(Size(3, 3), Position(1, 1));
  grid
    .addGoal(Position(1, 0))
    .addGoal(Position(0, 1))
    .addGoal(Position(2, 1))
    .addGoal(Position(1, 2));

  Tree treeResult = IDDFS::search(grid);
  auto result = treeResult.goalPath();
  std::vector<Direction> expected = { Direction::UP };

  EXPECT_EQ(result, expected);
}
TEST(IDDFS, path_with_walls_test_two_goals) {
  Grid grid(Size(11, 5), Position(0, 1));
  grid
    .addGoal(Position(7, 0))
    .addGoal(Position(10, 3))

    .addWall(Rectangle(2, 0, 2, 2))
    .addWall(Rectangle(8, 0, 1, 2))
    .addWall(Rectangle(10, 0, 1, 1))
    .addWall(Rectangle(2, 3, 1, 2))
    .addWall(Rectangle(3, 4, 3, 1))
    .addWall(Rectangle(9, 3, 1, 1))
    .addWall(Rectangle(8, 4, 2, 1));

  Tree treeResult = IDDFS::search(grid);
  auto result = treeResult.goalPath();
  std::vector<Direction> expected = {
    Direction::DOWN,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::UP,
    Direction::UP,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT
  };

  EXPECT_EQ(result, expected);
}

TEST(IDDFS, path_with_walls_test_one_goal) {
  // [ ][ ][W][W][ ][ ][ ][ ][W][ ][W]
  // [A][ ][W][W][ ][ ][ ][ ][W][ ][ ]
  // [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  // [ ][ ][W][ ][ ][ ][ ][ ][ ][W][G] 
  // [ ][ ][W][W][W][W][ ][ ][W][W][ ]

  Grid grid(Size(11, 5), Position(0, 1));
  grid
    .addGoal(Position(10, 3))

    .addWall(Rectangle(2, 0, 2, 2))
    .addWall(Rectangle(8, 0, 1, 2))
    .addWall(Rectangle(10, 0, 1, 1))
    .addWall(Rectangle(2, 3, 1, 2))
    .addWall(Rectangle(3, 4, 3, 1))
    .addWall(Rectangle(9, 3, 1, 1))
    .addWall(Rectangle(8, 4, 2, 1));

  Tree treeResult = IDDFS::search(grid);
  auto result = treeResult.goalPath();
  std::vector<Direction> expected = {
    Direction::DOWN,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::DOWN
  };

  EXPECT_EQ(result, expected);
}
TEST(IDDFS, should_throw_when_path_is_blocked) {
  // [ ][W][ ]
  // [A][W][G]
  // [ ][W][ ]
  Grid grid(Size(3, 3), Position(0, 1));
  grid
    .addGoal(Position(2, 0))
    .addWall(Rectangle(1, 0, 1, 3));

  EXPECT_THROW(IDDFS::search(grid), NoPathFoundException);
}
TEST(IDDFS, should_throw_when_no_path_found_one_cell) {
  // [A]
  Grid grid(Size(1, 1), Position(0, 0));
  EXPECT_THROW(IDDFS::search(grid), NoPathFoundException);
}
TEST(IDDFS, should_throw_when_no_path_found_many_cells) {
  // [ ][ ][ ]
  // [ ][A][ ]
  // [ ][ ][ ]
  Grid grid(Size(3, 3), Position(1, 1));
  EXPECT_THROW(IDDFS::search(grid), NoPathFoundException);
}