#include "gtest/gtest.h"
#include "solution.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

TEST(Solution, BrutalForce) {
    Solution s;
    size_t len;
    int data1[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    len = sizeof(data1) / sizeof(data1[0]);
    EXPECT_EQ(s.maxSubSumBrutal(data1, len,  4), 39);

    int data2[] = {100, 200, 300, 400};
    len = sizeof(data2) / sizeof(data2[0]);
    EXPECT_EQ(s.maxSubSumBrutal(data2, len,  2), 700);

    /* EXPECT_EQ(s.maxSubSumBrutal(data2, len,  5), 700); */
}

TEST(Solution, WindowSliding) {
    Solution s;
    size_t len;
    int data1[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    len = sizeof(data1) / sizeof(data1[0]);
    EXPECT_EQ(s.maxSubWindowSliding(data1, len,  4), 39);

    int data2[] = {100, 200, 300, 400};
    len = sizeof(data2) / sizeof(data2[0]);
    EXPECT_EQ(s.maxSubWindowSliding(data2, len,  2), 700);

    /* EXPECT_EQ(s.maxSubSumBrutal(data2, len,  5), 700); */
}
