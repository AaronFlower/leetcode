#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

TEST(Solution, addOperators) {
    Solution s;
    vector<int> originSet{3, 34, 4, 12, 5, 2};
    int sum;

    EXPECT_EQ(s.checkIsSubsetSumRecursion(originSet, originSet.size(), 9), true);

    originSet = {1, 8, 2, 5};
    sum = 4;
    EXPECT_EQ(s.checkIsSubsetSumRecursion(originSet, originSet.size(), sum), false);
}
