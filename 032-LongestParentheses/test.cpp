#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

TEST(LongestValidParentheses, DynamicProgramming) {
    Solution s;
    string str(")()");
    EXPECT_EQ(s.longestValidParentheses(str), 2);
    str = "()()()(()((()))()";
    EXPECT_EQ(s.longestValidParentheses(str), 10);
    str = "";
    EXPECT_EQ(s.longestValidParentheses(str), 0);
    str = "(";
    EXPECT_EQ(s.longestValidParentheses(str), 0);
    str = ")";
    EXPECT_EQ(s.longestValidParentheses(str), 0);
    str = "()";
    EXPECT_EQ(s.longestValidParentheses(str), 2);
    str = ")(";
    EXPECT_EQ(s.longestValidParentheses(str), 0);
}
