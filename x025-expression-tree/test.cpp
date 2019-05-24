#include "gtest/gtest.h"
#include "solution.h"



TEST(SuffixTree, Empty) {
    string s{""};
    tree t(s);
    EXPECT_EQ(t.inOrder(), "");
    EXPECT_EQ(t.preOrder(), "");
    EXPECT_EQ(t.postOrder(), "");
}

TEST(SuffixTree, Ex1) {
    string s{"ab+cde+**"};
    tree t(s);
    EXPECT_EQ(t.inOrder(), "a+b*c*d+e");
    EXPECT_EQ(t.preOrder(), "*+ab*c+de");
    EXPECT_EQ(t.preOrderS(), "*+ab*c+de");
    EXPECT_EQ(t.postOrder(), "ab+cde+**");
}


TEST(SuffixTree, Ex2) {
    string s{"ab+"};
    tree t(s);
    EXPECT_EQ(t.inOrder(), "a+b");
    EXPECT_EQ(t.preOrder(), "+ab");
    EXPECT_EQ(t.preOrderS(), "+ab");
    EXPECT_EQ(t.postOrder(), "ab+");
}



TEST(SuffixTree, Ex3) {
    string s{"ab*c+"};
    tree t(s);
    EXPECT_EQ(t.preOrder(), "+*abc");
    EXPECT_EQ(t.preOrderS(), "+*abc");
}
