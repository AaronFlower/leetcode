#include "gtest/gtest.h"
#include "solution.h"

TEST(KthElement, PriorityQueue) {
    Solution s;
    vector<int> nums;

    nums = {3,2,1,5,6,4};
    EXPECT_EQ(s.findKthLargest(nums, 2), 5);

    nums = {3,2,3,1,2,4,5,5,6};
    EXPECT_EQ(s.findKthLargest(nums, 4), 4);
}

TEST(KthElement, PriorityQueue1) {
    Solution s;
    vector<int> nums;

    nums = {3,2,1,5,6,4};
    EXPECT_EQ(s.findKthLargest1(nums, 2), 5);

    nums = {3,2,3,1,2,4,5,5,6};
    EXPECT_EQ(s.findKthLargest1(nums, 4), 4);
}


TEST(KthElement, PriorityQueue2) {
    Solution s;
    vector<int> nums;

    nums = {3,2,1,5,6,4};
    EXPECT_EQ(s.findKthLargest2(nums, 2), 5);

    nums = {3,2,3,1,2,4,5,5,6};
    EXPECT_EQ(s.findKthLargest2(nums, 4), 4);
}
