#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <iostream>
#include <cstring>

TEST(Tree, createTree) {
    Solution s;
    /* EXPECT_EQ(s.longestWord({"w","wo","wor","worl", "world"}), "world"); */
    vector<string> words = {"w","wo","wor","worl", "world"};
    EXPECT_EQ(s.longestWord(words), "world");
    words = {"a","banana","app","appl","ap","apply","apple"};
    EXPECT_EQ(s.longestWord(words), "apple");

    /* EXPECT_EQ(s.search("w"), true); */
    /* EXPECT_EQ(s.search("wo"), true); */
    /* EXPECT_EQ(s.search("wor"), true); */
    /* EXPECT_EQ(s.search("worl"), true); */
    /* EXPECT_EQ(s.search("world"), true); */
    /* EXPECT_EQ(s.search("world!"), false); */

    /* EXPECT_EQ(s.longestWordSearch(), "world"); */
}

/* TEST(Trie, he) { */
/*     Solution s; */
/*     s.longestWord({"h","he","her","b", "by", "bye"}); */
/*     EXPECT_EQ(s.longestWordSearch(), "bye"); */
/*     s.longestWord({"h","hello"}); */
/*     EXPECT_EQ(s.longestWordSearch(), "h"); */
/*     s.longestWord({"hello"}); */
/*     EXPECT_EQ(s.longestWordSearch(), ""); */
/*     s.longestWord({}); */
/*     EXPECT_EQ(s.longestWordSearch(), ""); */
/* } */

