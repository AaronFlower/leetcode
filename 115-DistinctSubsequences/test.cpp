#include "gtest/gtest.h"
#include "solution.h"

TEST(NumDistinct, NaiveRecursive) {
    Solution s;
    string x, y;
    x = "babgbag";
    y = "bag"; 
    EXPECT_EQ(s.numDistinctRecursive(x, y), 5);

    x = "rabbbit";
    y = "rabbit";
    EXPECT_EQ(s.numDistinctRecursive(x, y), 3);

    x = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
    y = "bddabdcae";
    EXPECT_EQ(s.numDistinctRecursive(x, y), 10582116);
}

TEST(NumDistinct, DP) {
    Solution s;
    string x, y;
    x = "babgbag";
    y = "bag"; 
    EXPECT_EQ(s.numDistinct(x, y), 5);

    x = "rabbbit";
    y = "rabbit";
    EXPECT_EQ(s.numDistinct(x, y), 3);

    x = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
    y = "bddabdcae";
    EXPECT_EQ(s.numDistinct(x, y), 10582116);
}
