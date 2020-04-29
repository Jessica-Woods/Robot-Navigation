#include "gtest/gtest.h"

#include "../Robot-Navigation/search_algorithms/IDDFS.h"
#include "../Robot-Navigation/search_algorithms/DFS.h"
#include "../Robot-Navigation/search_algorithms/BFS.h"
#include "../Robot-Navigation/search_algorithms/IDAStar.h"

#include "../Robot-Navigation/exceptions/NoPathFoundException.h"

#include <algorithm>

TEST(Comparison, IDDFS_finds_closer_goal_when_DFS_tunnel_visions) {
  // [G][ ][ ][ ]
  // [ ][ ][ ][ ]
  // [ ][ ][G][ ]
  // [ ][ ][ ][A]

  Grid grid(Size(4, 4), Position(3, 3));

  grid
    .addGoal(Position(0, 0))
    .addGoal(Position(2, 2));

  Tree iddfsTree = IDDFS::search(grid);
  auto iddfsPath = iddfsTree.goalPath();

  Tree dfsTree = DFS::search(grid);
  auto dfsPath = dfsTree.goalPath();
  
  EXPECT_GT(dfsPath.size(), iddfsPath.size());
}

TEST(Comparison, IDDFS_should_seearch_less_nodes_then_BFS_when_tunnel_vision_helps) {
  // [G][ ][ ][ ]
  // [ ][ ][ ][ ]
  // [ ][ ][ ][ ]
  // [ ][ ][ ][ ]
  // [ ][ ][ ][A]

  Grid grid(Size(4, 5), Position(3, 4));
  grid
    .addGoal(Position(0, 0));

  Tree iddfsTree = IDDFS::search(grid);
  auto iddfsTotalNodes = iddfsTree.totalNodes();

  Tree bfsTree = BFS::search(grid);
  auto bfsTotalNodes = bfsTree.totalNodes();

  EXPECT_GT(bfsTotalNodes, iddfsTotalNodes);
}

TEST(Comparison, IDDFS_should_seearch_less_nodes_then_BFS_when_tunnel_vision_helps_2) {
  // [A][ ][ ][ ]
  // [ ][ ][ ][ ]
  // [ ][ ][ ][ ]
  // [ ][ ][ ][ ]
  // [ ][ ][ ][G]

  Grid grid(Size(10, 10), Position(0, 0));
  grid
    .addGoal(Position(3, 4));

  Tree iddfsTree = IDDFS::search(grid);
  auto iddfsTotalNodes = iddfsTree.totalNodes();

  Tree idasTree = IDAStar::search(grid);
  auto idasTotalNodes = idasTree.totalNodes();

  EXPECT_LT(iddfsTotalNodes, idasTotalNodes);
}


TEST(Comparison, IDDFS_should_seearch_less_nodes_then_BFS_when_tunnel_vision_helps_3) {
  // [A][W][G][W]
  // [ ][ ][W][ ]
  // [ ][ ][ ][ ]
  // [ ][ ][ ][ ]
  // [ ][ ][ ][G]

  Grid grid(Size(10, 10), Position(0, 0));
  grid
    .addGoal(Position(3, 4))
    .addWall(Rectangle(1, 0))
    .addWall(Rectangle(3, 0))
    .addWall(Rectangle(2, 1));

  Tree iddfsTree = IDDFS::search(grid);
  auto iddfsTotalNodes = iddfsTree.totalNodes();

  Tree idasTree = IDAStar::search(grid);
  auto idasTotalNodes = idasTree.totalNodes();

  EXPECT_LT(iddfsTotalNodes, idasTotalNodes);
}
