#include "gtest/gtest.h"
#include "solution.h"

TEST(MaxSubarray, Naive) {
    Solution s;
    vector<int> t;

    t = {};
    EXPECT_EQ(s.maxSubarray(t), 0);

    t = {-2, 1};
    EXPECT_EQ(s.maxSubarray(t), 1);

    t = {3, 2};
    EXPECT_EQ(s.maxSubarray(t), 5);

    t = {-2,1,-3,4,-1,2,1,-5,4};
    EXPECT_EQ(s.maxSubarray(t), 6);
}

TEST(MaxSubarray, TimeBigO_n2) {
    Solution s;
    vector<int> t;

    t = {};
    EXPECT_EQ(s.maxSubarrayBig_On2(t), 0);

    t = {-2, 1};
    EXPECT_EQ(s.maxSubarrayBig_On2(t), 1);

    t = {3, 2};
    EXPECT_EQ(s.maxSubarrayBig_On2(t), 5);

    t = {-2,1,-3,4,-1,2,1,-5,4};
    EXPECT_EQ(s.maxSubarrayBig_On2(t), 6);
}

