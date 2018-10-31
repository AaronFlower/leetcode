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
    Trie r({"by"});
    EXPECT_EQ(r.search("by"), true);
    EXPECT_EQ(r.search("bye"), false);
    EXPECT_EQ(r.search("a"), false);

    EXPECT_EQ(r.deleteKey(""), false);
    EXPECT_EQ(r.deleteKey("a"), false);
    EXPECT_EQ(r.deleteKey("b"), false);

    EXPECT_EQ(r.search("by"), true);
    r.deleteKey("by");
    EXPECT_EQ(r.search("by"), false);
}

TEST(Trie, DeleteBY) {
    // Delete nodes from end of key until first leaf node of longest prefix key.
    Trie r({"b", "by"});
    EXPECT_EQ(r.search("by"), true);
    EXPECT_EQ(r.search("bye"), false);
    EXPECT_EQ(r.search("a"), false);

    EXPECT_EQ(r.search("b"), true);
    EXPECT_EQ(r.search("by"), true);
    r.deleteKey("by");
    EXPECT_EQ(r.search("by"), false);
    EXPECT_EQ(r.search("b"), true);
}

TEST(Trie, DeleteB) {
    // Key is prefix key of another long key in trie. Unmark the leaf node.
    Trie r({"b", "by"});
    EXPECT_EQ(r.search("by"), true);
    EXPECT_EQ(r.search("bye"), false);
    EXPECT_EQ(r.search("a"), false);

    EXPECT_EQ(r.search("b"), true);
    EXPECT_EQ(r.search("by"), true);
    r.deleteKey("b");
    EXPECT_EQ(r.search("b"), false);
    EXPECT_EQ(r.search("by"), true);
}
