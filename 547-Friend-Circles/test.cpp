#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

TEST(UionFind, FindCircle) {
    Solution s;

    vector<vector<int>> mat;
    mat = {
         {1,1,0},
         {1,1,0},
         {0,0,1}
    };



    EXPECT_EQ(s.findCircleNum(mat), 2);

    mat = {
         {1,1,0},
         {1,1,1},
         {0,1,1}
    };
    EXPECT_EQ(s.findCircleNum(mat), 1);

    mat = {
         {1,0,0},
         {0,1,0},
         {0,0,1}
    };
    EXPECT_EQ(s.findCircleNum(mat), 3);
}
