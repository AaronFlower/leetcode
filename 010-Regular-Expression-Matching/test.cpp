#include "gtest/gtest.h"
#include "solution.h"

TEST(Regulare, isMatch) {
    Solution s;
    EXPECT_EQ(s.isMatch("aa", "a"), false);
    EXPECT_EQ(s.isMatch("a", "ab*"), true);
    EXPECT_EQ(s.isMatch("a", "ab*a"), false);
    EXPECT_EQ(s.isMatch("abcd", "d*"), false);
    EXPECT_EQ(s.isMatch("aa", "a*"), true);
    EXPECT_EQ(s.isMatch("aaa", "a*a"), true);
    EXPECT_EQ(s.isMatch("ab", ".*"), true);
    EXPECT_EQ(s.isMatch("aab", "c*a*b"), true);
    EXPECT_EQ(s.isMatch("mississippi", "mis*is*p*."), false);
}
