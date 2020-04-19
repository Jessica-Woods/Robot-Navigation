#include "gtest/gtest.h"

#include "../Robot-Navigation/search_algorithms/AStar.h"
#include "../Robot-Navigation/search_algorithms/GBFS.h"
#include "../Robot-Navigation/exceptions/NoPathFoundException.h"

#include <algorithm>
TEST(AStar, astar_should_be_better_then_gbfs_if_a_concave_wall_is_involved) {
  // [ ][ ][ ][ ][ ][W][G]
  // [A][ ][ ][ ][ ][W][ ]
  // [ ][ ][ ][ ][ ][W][ ]
  // [ ][W][W][W][W][W][ ]
  // [ ][ ][ ][ ][ ][ ][ ]
  Grid grid(Size(7, 5), Position(0, 1));
  grid
    .addGoal(Position(6, 0))
    .addWall(Rectangle(1, 3, 4, 1))
    .addWall(Rectangle(5, 0, 1, 4));

  Tree astarResult = AStar::search(grid);
  Tree gbfsResult = GBFS::search(grid);

  EXPECT_LT(astarResult.totalNodes(), gbfsResult.totalNodes());
}