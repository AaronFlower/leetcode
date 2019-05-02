#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

using testing::ElementsAre;

TEST(Solution, DescentRadixSort) {
    Solution s;
    vector<int> data = {170, 45, 75, 90, 802, 24, 2, 66};
    s.radixSort(data);
    EXPECT_THAT(data, ElementsAre(2, 24, 45, 66, 75, 90, 170, 802));
}
