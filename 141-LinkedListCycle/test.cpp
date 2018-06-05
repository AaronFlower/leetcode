#include "gtest/gtest.h"
#include "solution.h"

TEST(LinkedListCycle, create) {
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

TEST(LinkedListCycle, hasCycle) {
    Solution s;
    LinkList list;
    vector<int> data;

    data = {};
    s.vectorToLinkList(list, data);
    EXPECT_EQ(false, s.hasCycle(list)); 

    s.vectorToLinkList(list, {1, 2, 3, 4, 5});
    EXPECT_EQ(list->val, 1);
    EXPECT_EQ(list->next->val, 2);
    EXPECT_EQ(list->next->next->val, 3);
    EXPECT_EQ(list->next->next->next->val, 4);
    EXPECT_EQ(list->next->next->next->next->val, 5);
    EXPECT_EQ(list->next->next->next->next->next, nullptr);
    EXPECT_EQ(false, s.hasCycle(list)); 

    list->next->next->next->next->next = list->next->next->next;
    EXPECT_EQ(true, s.hasCycle(list)); 
}
