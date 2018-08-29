#include "gtest/gtest.h"
#include "solution.h"

TEST(LinkList, Case1) {
    Solution s;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    EXPECT_EQ(s.numIslands(grid), 1);
}

TEST(LinkList, Small) {
    Solution s;
    vector<vector<char>> grid = {
        {'1','1'},
        {'0','1'}
    };
    EXPECT_EQ(s.numIslands(grid), 1);
}

TEST(LinkList, UnionFindByRank) {
    Solution s;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    EXPECT_EQ(s.numIslandsByUnionRank(grid), 1);
}

TEST(LinkList, UnionFindByRankSmall) {
    Solution s;
    vector<vector<char>> grid = {
        {'1','1'},
        {'0','1'}
    };
    EXPECT_EQ(s.numIslandsByUnionRank(grid), 1);
}

