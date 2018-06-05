#include "gtest/gtest.h"
#include "solution.h"

TEST(RemoveDuplicates, create) {
    Solution s;
    LinkList list;
    vector<int> t;

    t = {};
    s.vectorToLinkList(list, t);
    EXPECT_EQ(list, nullptr);

    t = {3, 2};
    s.vectorToLinkList(list, t);
    EXPECT_EQ(list->val, 3);
    EXPECT_EQ(list->next->val, 2);
    EXPECT_EQ(list->next->next, nullptr);
}

TEST(RemoveDuplicates, remove) {
    Solution s;
    LinkList list;
    vector<int> data;

    data = {};
    s.vectorToLinkList(list, data);
    EXPECT_EQ(nullptr, s.removeDuplicates(list)); 

    s.vectorToLinkList(list, {1, 2, 2, 4, 4});
    EXPECT_EQ(list->val, 1);
    EXPECT_EQ(list->next->val, 2);
    EXPECT_EQ(list->next->next->val, 2);
    EXPECT_EQ(list->next->next->next->val, 4);
    EXPECT_EQ(list->next->next->next->next->val, 4);
    EXPECT_EQ(list->next->next->next->next->next, nullptr);

    LinkList uniqueList = s.removeDuplicates(list);
    EXPECT_EQ(uniqueList->val, 1);
    EXPECT_EQ(uniqueList->next->val, 2);
    EXPECT_EQ(uniqueList->next->next->val, 4);
    EXPECT_EQ(uniqueList->next->next->next, nullptr);
}
