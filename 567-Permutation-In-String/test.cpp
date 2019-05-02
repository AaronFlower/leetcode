#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

TEST(CheckInclusion, Sliding) {
    Solution s;
    string s1 = "ab";
    string s2 = "eidbsaooo";
    EXPECT_EQ(s.checkInclusion(s1, s2), false);

    s1 = "ab";
    s2 = "eidbaooo";
    EXPECT_EQ(s.checkInclusion(s1, s2), true);

    s1 = "hello";
    s2 = "ooolleoooleh";
    EXPECT_EQ(s.checkInclusion(s1, s2), false);

    s1 = "ky";
    s2 = "ainwkckifykxlribaypk";
    EXPECT_EQ(s.checkInclusion(s1, s2), true);
}
