#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

TEST(Median, PriorityQueue) {
    Solution s;

    EXPECT_EQ(s.findMedianSortedArrays({1, 2}, {3, 4}), 2.5);
}
