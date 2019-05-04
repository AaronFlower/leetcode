#include "gtest/gtest.h"
#include "solution.h"

/*
 * 用递归的时间性能是 O(2^n), 是不会被 AC 的，只会 Time Limit Exceed.
 */
TEST(CanPartiion, Recursive) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(s.canPartitionRecursive(nums), true);

    nums = {1, 3, 4};
    EXPECT_EQ(s.canPartitionRecursive(nums), true);

    nums = {1,5,11,5};
    EXPECT_EQ(s.canPartitionRecursive(nums), true);

    nums = {1,2,3,5};
    EXPECT_EQ(s.canPartitionRecursive(nums), false);
}

TEST(CanPartiion, DpBottomUP) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(s.canPartition(nums), true);

    nums = {1, 3, 4};
    EXPECT_EQ(s.canPartition(nums), true);

    nums = {1,5,11,5};
    EXPECT_EQ(s.canPartition(nums), true);

    nums = {3, 1, 1, 2, 2, 1};
    EXPECT_EQ(s.canPartition(nums), true);
}


TEST(CanPartiion, DpTopDown) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(s.canPartitionTopDown(nums), true);

    nums = {1, 3, 4};
    EXPECT_EQ(s.canPartitionTopDown(nums), true);

    nums = {1,5,11,5};
    EXPECT_EQ(s.canPartitionTopDown(nums), true);

    nums = {3, 1, 1, 2, 2, 1};
    EXPECT_EQ(s.canPartitionTopDown(nums), true);
}
