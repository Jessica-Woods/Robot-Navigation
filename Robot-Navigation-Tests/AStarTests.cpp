#include "gtest/gtest.h"

#include "../Robot-Navigation/search_algorithms/AStar.h"
#include "../Robot-Navigation/search_algorithms/GBFS.h"
#include "../Robot-Navigation/exceptions/NoPathFoundException.h"

#include <algorithm>
TEST(AStar, astar_should_be_better_then_gbfs_if_a_maze_is_involved) {
  // [ ][W][ ][ ][ ][W][ ]
  // [ ][W][ ][W][ ][W][ ]
  // [ ][W][ ][W][ ][W][ ]
  // [A][ ][ ][W][ ][ ][G]
  // [ ][W][W][W][W][W][ ]
  // [ ][ ][ ][ ][ ][ ][ ]
  Grid grid(Size(7, 6), Position(0, 3));
  grid
    .addGoal(Position(6, 3))
    .addWall(Rectangle(1, 0, 1, 3))
    .addWall(Rectangle(1, 4, 5, 1))
    .addWall(Rectangle(3, 1, 1, 3))
    .addWall(Rectangle(5, 0, 1, 3));

  Tree astarResult = AStar::search(grid);
  Tree gbfsResult = GBFS::search(grid);

  EXPECT_LT(astarResult.goalPath().size(), gbfsResult.goalPath().size());
}