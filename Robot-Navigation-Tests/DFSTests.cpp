#include "gtest/gtest.h"

#include "../Robot-Navigation/DFS.h"
#include "../Robot-Navigation/NoPathFoundException.h"

#include <algorithm>
TEST(DFS, node_count_test) {
  // [ ][G][ ]
  // [G][A][G]
  // [ ][G][ ]
  Grid grid(3, 3, Position(1, 1));
  grid
    .addGoal(Position(1, 0))
    .addGoal(Position(0, 1))
    .addGoal(Position(2, 1))
    .addGoal(Position(1, 2));

  Tree treeResult = DFS::search(grid);

  int result = treeResult.totalNodes();
  int expected = 5;
  
  EXPECT_EQ(result, expected);
}

TEST(DFS, bias_upwards_test) {
  // [ ][G][ ]
  // [G][A][G]
  // [ ][G][ ]
  Grid grid(3, 3, Position(1, 1));
  grid
    .addGoal(Position(1, 0))
    .addGoal(Position(0, 1))
    .addGoal(Position(2, 1))
    .addGoal(Position(1, 2));

  Tree treeResult = DFS::search(grid);
  auto result = treeResult.goalPath();
  std::vector<Direction> expected = { Direction::UP };

  EXPECT_EQ(result, expected);
}
TEST(DFS, path_with_walls_test_two_goals) {
  Grid grid(11, 5, Position(0, 1));
  grid
    .addGoal(Position(7, 0))
    .addGoal(Position(10, 3))

    .addWall(Position(2, 0), 2, 2)
    .addWall(Position(8, 0), 1, 2)
    .addWall(Position(10, 0), 1, 1)
    .addWall(Position(2, 3), 1, 2)
    .addWall(Position(3, 4), 3, 1)
    .addWall(Position(9, 3), 1, 1)
    .addWall(Position(8, 4), 2, 1);

  Tree treeResult = DFS::search(grid);
  auto result = treeResult.goalPath();
  std::vector<Direction> expected = { 
    Direction::UP, 
    Direction::RIGHT,
    Direction::DOWN,
    Direction::DOWN,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::DOWN,
    Direction::RIGHT,
    Direction::UP,
    Direction::UP,
    Direction::UP,
    Direction::RIGHT,
    Direction::DOWN,
    Direction::DOWN,
    Direction::DOWN,
    Direction::RIGHT,
    Direction::UP,
    Direction::UP,
    Direction::UP,
    Direction::RIGHT
  };

  EXPECT_EQ(result, expected);
}

TEST(DFS, path_with_walls_test_one_goal) {
  // [ ][ ][W][W][ ][ ][ ][ ][W][ ][W]
  // [A][ ][W][W][ ][ ][ ][ ][W][ ][ ]
  // [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  // [ ][ ][W][ ][ ][ ][ ][ ][ ][W][G] 
  // [ ][ ][W][W][W][W][ ][ ][W][W][ ]

  Grid grid(11, 5, Position(0, 1));
  grid
    .addGoal(Position(10, 3))

    .addWall(Position(2, 0), 2, 2)
    .addWall(Position(8, 0), 1, 2)
    .addWall(Position(10, 0), 1, 1)
    .addWall(Position(2, 3), 1, 2)
    .addWall(Position(3, 4), 3, 1)
    .addWall(Position(9, 3), 1, 1)
    .addWall(Position(8, 4), 2, 1);

  Tree treeResult = DFS::search(grid);
  auto result = treeResult.goalPath();
  std::vector<Direction> expected = {
    Direction::UP,
    Direction::RIGHT,
    Direction::DOWN,
    Direction::DOWN,
    Direction::RIGHT,
    Direction::RIGHT,
    Direction::DOWN,
    Direction::RIGHT,
    Direction::UP,
    Direction::UP,
    Direction::UP,
    Direction::RIGHT,
    Direction::DOWN,
    Direction::DOWN,
    Direction::DOWN,
    Direction::RIGHT,
    Direction::UP,
    Direction::UP,
    Direction::UP,
    Direction::RIGHT,
    Direction::DOWN,
    Direction::DOWN,
    Direction::DOWN,
    Direction::RIGHT,
    Direction::UP,
    Direction::RIGHT,
    Direction::UP,
    Direction::RIGHT,
    Direction::DOWN,
    Direction::DOWN
  };

  EXPECT_EQ(result, expected);
}
TEST(DFS, should_throw_when_path_is_blocked) {
  // [ ][W][ ]
  // [A][W][G]
  // [ ][W][ ]
  Grid grid(3, 3, Position(0, 1));
  grid
    .addGoal(Position(2, 0))
    .addWall(Position(1,0), 1, 3);

  EXPECT_THROW(DFS::search(grid), NoPathFoundException);
}
TEST(DFS, should_throw_when_no_path_found_one_cell) {
  // [A]
  Grid grid(1, 1, Position(0, 0));
  EXPECT_THROW(DFS::search(grid), NoPathFoundException);
}
TEST(DFS, should_throw_when_no_path_found_many_cells) {
  // [ ][ ][ ]
  // [ ][A][ ]
  // [ ][ ][ ]
  Grid grid(3, 3, Position(1, 1));
  EXPECT_THROW(DFS::search(grid), NoPathFoundException);
}