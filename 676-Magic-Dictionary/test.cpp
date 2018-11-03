#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <iostream>
#include <cstring>

TEST(Tree, MagicDictionary) {
    MagicDictionary obj;
    vector<string> dict{"bye"};
    obj.buildDict(dict);
    EXPECT_EQ(obj.search(""), false);
    EXPECT_EQ(obj.search("bye"), false);
    EXPECT_EQ(obj.search("cat"), false);
    EXPECT_EQ(obj.search("rye"), true);
    EXPECT_EQ(obj.search("bce"), true);
    EXPECT_EQ(obj.search("bya"), true);
}


TEST(MagicDictionary, search) {
    MagicDictionary obj;
    vector<string> dict{"hello", "hallo", "leetcode"};
    obj.buildDict(dict);
    EXPECT_EQ(obj.search("hallo"), false);
    EXPECT_EQ(obj.search("hello"), false);
    EXPECT_EQ(obj.search("hhllo"), true);
    EXPECT_EQ(obj.search("hell"), false);
    EXPECT_EQ(obj.search("leetcoded"), false);
}

