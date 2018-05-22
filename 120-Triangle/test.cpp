#include "gtest/gtest.h"
#include "solution.h"

TEST(TriangleSum, DP) {
    Solution s;

    vector<vector<int>> t = {{2},{3,4},{6,5,7},{4,1,8,3}};
    EXPECT_EQ(s.minimumTotal(t), 11);
} 
