#include "gtest/gtest.h"
#include "solution.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

TEST(Solution, Null) {
    Solution s;
    vector<int> data;
    EXPECT_EQ(s.binarySearch(data, 2), -1);
}

TEST(Solution, Missed) {
    Solution s;
    vector<int> data;
    EXPECT_EQ(s.binarySearch(data, 2), -1);

    data = {0, 1, 4, 6};
    EXPECT_EQ(s.binarySearch(data, 5), -1);
    EXPECT_EQ(s.binarySearch(data, -1), -1);
    EXPECT_EQ(s.binarySearch(data, 7), -1);

    data = {0, 1, 2, 4, 6};
    EXPECT_EQ(s.binarySearch(data, 5), -1);
    EXPECT_EQ(s.binarySearch(data, -1), -1);
    EXPECT_EQ(s.binarySearch(data, 7), -1);
}

TEST(Solution, RightMost) {
    Solution s;
    vector<int> data; 

    data = {0};
    EXPECT_EQ(s.binarySearch(data, 0), 0);
    data = {0, 1,  4, 6};
    EXPECT_EQ(s.binarySearch(data, 6), 3);
    data = {0, 1, 2, 4, 6};
    EXPECT_EQ(s.binarySearch(data, 6), 4);
}

TEST(Solution, LeftMost) {
    Solution s;
    vector<int> data; 

    data = {0};
    EXPECT_EQ(s.binarySearch(data, 0), 0);
    data = {0, 1,  4, 6};
    EXPECT_EQ(s.binarySearch(data, 0), 0);
    data = {0, 1, 2, 4, 6};
    EXPECT_EQ(s.binarySearch(data, 0), 0);
}

TEST(Solution, Middle) {
    Solution s;
    vector<int> data; 

    data = {0};
    EXPECT_EQ(s.binarySearch(data, 0), 0);

    data = {0, 1, 4, 6};
    EXPECT_EQ(s.binarySearch(data, 1), 1);
    EXPECT_EQ(s.binarySearch(data, 4), 2);
    data = {0, 1, 2, 4, 6};
    EXPECT_EQ(s.binarySearch(data, 2), 2);
}

TEST(Solution, RandPos) {
    Solution s;
    vector<int> data; 

    data = {0};
    EXPECT_EQ(s.binarySearch(data, 0), 0);

    data = {0, 1, 4, 6, 7, 8};
    EXPECT_EQ(s.binarySearch(data, 1), 1);
    data = {0, 1, 2, 4, 6, 7, 8, 9};
    EXPECT_EQ(s.binarySearch(data, 8), 6);
}
