#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <iostream>

TEST(test, AllocFunc) {
    SegmentTree seg;
    vector<int> nums{-28,-39,53,65,11,-56,-65,-39,-43,97};
    seg.build(nums);
}

TEST(test, INIT) {
    SegmentTree tree;
    vector<int> nums{7, 2, 3, 5, 1, 0};
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

TEST(test, buildTree) {
    SegmentTree tree;
    vector<int> nums{-28,-39,53,65,11,-56,-65,-39,-43,97};
    tree.build(nums);
    EXPECT_EQ(-28, tree.sum(0, 0));
}
