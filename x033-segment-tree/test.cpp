#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <iostream>

TEST(test, INIT) {
    SegmentTree tree;
    vector<int> nums{7, 2, 3, 5, 1};
    tree.build(nums);
    EXPECT_EQ(18, tree.sum(0, 4));
    EXPECT_EQ(17, tree.sum(0, 3));
    EXPECT_EQ(10, tree.sum(1, 3));
    EXPECT_EQ(5, tree.sum(1, 2));
    EXPECT_EQ(3, tree.sum(2, 2));
    int idx = 2;
    int value = 1;
    tree.update(idx, value);
    EXPECT_EQ(16, tree.sum(0, 4));
    EXPECT_EQ(9, tree.sum(1, 4));
    EXPECT_EQ(1, tree.sum(2, 2));
    EXPECT_EQ(3, tree.sum(1, 2));
}
