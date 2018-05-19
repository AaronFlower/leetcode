#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

TEST(UniquePaths, DP) {
    Solution s;
    vector<vector<int>> grid;
    EXPECT_EQ(s.uniquePathsWithObstacles(grid), 0);

    grid = {{1}};
    EXPECT_EQ(s.uniquePathsWithObstacles(grid), 0);
    grid = {{0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(grid), 1);

    grid = {{0, 1, 0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(grid), 0);

    grid = {{0}, {1}, {0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(grid), 0);

    grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(grid), 6);

    grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(grid), 2);

    grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    EXPECT_EQ(s.uniquePathsWithObstacles(grid), 0);

    grid = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(grid), 20);
}
