#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

TEST(MinWindowSubstring, Sliding) {
    Solution s;
    string x = "adobecodebanc";
    string y = "abc";
    EXPECT_EQ(s.minWindow(x, y), "banc");

    x = "ABBBCA";
    y = "ABC";
    EXPECT_EQ(s.minWindow(x, y), "BCA");
}
