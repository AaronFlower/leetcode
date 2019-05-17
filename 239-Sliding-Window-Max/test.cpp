#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <vector>
#include <queue>

using std::vector;
using std::cout;
using std::endl;
using std::priority_queue;
using testing::ElementsAre;


TEST(maxSlidingWindow, Deque1) {
    vector<int> data{1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s;
    vector<int> res = s.maxSlidingWindowDeque1(data, k);
    EXPECT_THAT(res, ElementsAre(3,3,5,5,6,7));
}

TEST(maxSlidingWindow, Deque2) {
    vector<int> data{1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s;
    vector<int> res = s.maxSlidingWindowDeque2(data, k);
    EXPECT_THAT(res, ElementsAre(3,3,5,5,6,7));
}

TEST(maxSlidingWindow, Naive) {
    vector<int> data{1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s;
    vector<int> res = s.maxSlidingWindowNaive(data, k);
    EXPECT_THAT(res, ElementsAre(3,3,5,5,6,7));
}

TEST(maxSlidingWindow, Heap1) {
    vector<int> data{1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s;
    vector<int> res = s.maxSlidingWindowHeap1(data, k);
    EXPECT_THAT(res, ElementsAre(3,3,5,5,6,7));
}

TEST(maxSlidingWindow, Heap2) {
    vector<int> data{1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s;
    vector<int> res = s.maxSlidingWindowHeap2(data, k);
    EXPECT_THAT(res, ElementsAre(3,3,5,5,6,7));
}

TEST(maxSlidingWindow, Multiset) {
    vector<int> data{1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s;
    vector<int> res = s.maxSlidingWindowMultiSet(data, k);
    EXPECT_THAT(res, ElementsAre(3,3,5,5,6,7));
}
