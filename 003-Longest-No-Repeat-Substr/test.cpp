#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

TEST(TwoSum, BruteForce) {
    Solution s;

    EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
    EXPECT_EQ(s.lengthOfLongestSubstring("abba"), 2);
}
