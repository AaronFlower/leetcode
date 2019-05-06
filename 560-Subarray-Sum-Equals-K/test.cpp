#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

// BrutalForce 的方式，当数据量大的时候不能被 AC.
TEST(SubarraySumEqualsK, BrutalForce) {
    Solution s;
    vector<int> nums;

    nums = {1, 1, 1};
    EXPECT_EQ(s.subarraySumBrutalForce(nums, 2), 2);

    nums = {1, 2, 3, 2, 1, 5, 1};
    EXPECT_EQ(s.subarraySumBrutalForce(nums, 6), 4);
}

// BrutalForce2 的方式，当数据量大的时候不能被 AC.
TEST(SubarraySumEqualsK, BrutalForce2) {
    Solution s;
    vector<int> nums;

    nums = {1, 1, 1};
    EXPECT_EQ(s.subarraySum2(nums, 2), 2);

    nums = {1, 2, 3, 2, 1, 5, 1};
    EXPECT_EQ(s.subarraySum2(nums, 6), 4);
}

// Using HashMpa 的
TEST(SubarraySumEqualsK, HashMap) {
    Solution s;
    vector<int> nums;

    nums = {1, 1, 1};
    EXPECT_EQ(s.subarraySumMap(nums, 2), 2);

    nums = {1, 2, 3, 2, 1, 5, 1};
    EXPECT_EQ(s.subarraySumMap(nums, 6), 4);
}
