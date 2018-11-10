#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <iostream>
#include <cstring>

TEST(Tree, MagicDictionary) {
    Solution s;
    
    EXPECT_EQ(s.countSubstrings("aaa"), 6);
    EXPECT_EQ(s.countSubstrings("abc"), 3);
}

