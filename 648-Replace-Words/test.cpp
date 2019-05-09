#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <iostream>

TEST(Trie, ReplaceWords) {
    Solution s;

    vector<string> dict{"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";

    EXPECT_EQ(s.replaceWords(dict, sentence), "the cat was rat by the bat");
}
