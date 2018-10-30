#include "gtest/gtest.h"
#include "solution.h"

#include <iostream>

using std::cout;
using std::endl;

TEST(Solution, Trie) {
    Trie r({"the", "a", "there", "answer", "any", "by", "bye", "their"});
    
    EXPECT_EQ(r.search("the"), true);
    EXPECT_EQ(r.search("these"), false);
}
