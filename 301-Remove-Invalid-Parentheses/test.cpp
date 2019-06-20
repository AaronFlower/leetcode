#include "gtest/gtest.h"
#include "solution.h"

#include <iostream>

using std::cout;
using std::endl;

TEST(IsValid, UsingStack) {
    Solution s;
    EXPECT_EQ(s.isValid(""), true);
    EXPECT_EQ(s.isValid("()"), true);
    EXPECT_EQ(s.isValid("(())"), true);
    EXPECT_EQ(s.isValid("()()(())"), true);

    EXPECT_EQ(s.isValid("("), false);
    EXPECT_EQ(s.isValid(")"), false);
    EXPECT_EQ(s.isValid("()))"), false);
    EXPECT_EQ(s.isValid("()("), false);
}


TEST(IsValid, UsingCounter) {
    Solution s;
    EXPECT_EQ(s.isValidUsingCounter(""), true);
    EXPECT_EQ(s.isValidUsingCounter("()"), true);
    EXPECT_EQ(s.isValidUsingCounter("(())"), true);
    EXPECT_EQ(s.isValidUsingCounter("()()(())"), true);

    EXPECT_EQ(s.isValidUsingCounter("("), false);
    EXPECT_EQ(s.isValidUsingCounter(")"), false);
    EXPECT_EQ(s.isValidUsingCounter("()))"), false);
    EXPECT_EQ(s.isValidUsingCounter("()("), false);
}

TEST(RemoveInvalidParentheses, Backtrack) {
    Solution s;
    string str = ")()))())))";

    vector<string> res = s.removeInvalidParentheses(str);

    for (auto e : res) {
        cout << e << "\t";
    }
    cout << endl;
}
