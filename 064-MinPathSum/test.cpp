#include "gtest/gtest.h"
#include "solution.h"

TEST(UniquePaths, DP) {
    Solution s;
    vector<vector<int>> grid;

    grid = {{1}};
    EXPECT_EQ(s.minPathSum(grid), 1);
    grid = {{0}};
    EXPECT_EQ(s.minPathSum(grid), 0);

    grid = {{0, 1, 0}};
    EXPECT_EQ(s.minPathSum(grid), 1);

    grid = {{0}, {1}, {0}};
    EXPECT_EQ(s.minPathSum(grid), 1);

    grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    EXPECT_EQ(s.minPathSum(grid), 7);

    grid = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    EXPECT_EQ(s.minPathSum(grid), 0);
}
