#include "gtest/gtest.h"
#include "solution.h"

#include <iostream>

using std::cout;
using std::endl;

TEST(Solution, Trie) {
    Trie r({"the", "a", "there", "answer", "any", "by", "bye", "their"});
    
    EXPECT_EQ(r.search("the"), true);
    EXPECT_EQ(r.search("th"), false);
    EXPECT_EQ(r.search("these"), false);
    EXPECT_EQ(r.search("by"), true);
    EXPECT_EQ(r.search("bye"), true);
}

TEST(Trie, Delete) {
    Trie r({"by", "bye"});
    EXPECT_EQ(r.search("by"), true);
    EXPECT_EQ(r.search("bye"), true);
    EXPECT_EQ(r.search("a"), false);

    EXPECT_EQ(r.deleteKey(""), false);
    EXPECT_EQ(r.deleteKey("a"), false);
    EXPECT_EQ(r.deleteKey("bya"), false);
    EXPECT_EQ(r.deleteKey("byab"), false);
    EXPECT_EQ(r.deleteKey("b"), false);

    EXPECT_EQ(r.search("by"), true);
    EXPECT_EQ(r.deleteKey("by"), false);
    EXPECT_EQ(r.search("by"), false);

    /* EXPECT_EQ(r.search("bye"), true); */
    /* EXPECT_EQ(r.deleteKey("bye"), false); */
    /* EXPECT_EQ(r.search("bye"), false); */
}

TEST(Trie, DeleteBY) {
    Trie r({"by"});
    EXPECT_EQ(r.search("by"), true);
    EXPECT_EQ(r.search("bye"), false);
    EXPECT_EQ(r.search("a"), false);

    EXPECT_EQ(r.search("by"), true);
    EXPECT_EQ(r.deleteKey("by"), false);
    EXPECT_EQ(r.search("by"), false);
}
