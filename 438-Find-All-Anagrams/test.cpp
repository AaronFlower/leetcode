#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <string>

using testing::ElementsAre;

TEST(FindAnagrams, WindowSliding) {
    Solution s;
    EXPECT_THAT(s.findAnagrams("abab", "ababa"), ElementsAre());
    EXPECT_THAT(s.findAnagrams("abab", "ab"), ElementsAre(0, 1, 2));
    EXPECT_THAT(s.findAnagrams("acbab", "ab"), ElementsAre(2, 3));
    EXPECT_THAT(s.findAnagrams("cbaebabacd", "abc"), ElementsAre(0, 6));
}
