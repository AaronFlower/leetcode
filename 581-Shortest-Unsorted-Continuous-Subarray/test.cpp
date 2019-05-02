#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

TEST(findUnsortedSubarray, Sliding) {
    Solution s;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    EXPECT_EQ(s.findUnsortedSubarray(nums), 5);

    nums = {1, 2, 2, 3, 5, 7, 4, 4, 2, 8, 9, 7, 9, 10};
    EXPECT_EQ(s.findUnsortedSubarray(nums), 9);
    nums = {1, 2, 3, 4};
    EXPECT_EQ(s.findUnsortedSubarray(nums), 0);
}
