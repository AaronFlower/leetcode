#include "gtest/gtest.h"
#include "solution.h"

TEST(LinkList, create) {
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


TEST(LinkList, reverseUsingStack) {
    Solution s;
    LinkList list;
    vector<int> t;


    s.vectorToLinkList(list, {1, 2, 3, 4, 5});
    EXPECT_EQ(list->val, 1);
    EXPECT_EQ(list->next->val, 2);
    EXPECT_EQ(list->next->next->val, 3);
    EXPECT_EQ(list->next->next->next->val, 4);
    EXPECT_EQ(list->next->next->next->next->val, 5);
    EXPECT_EQ(list->next->next->next->next->next, nullptr);
    s.reverseListWithStack(list);
    EXPECT_EQ(list->val, 5);
    EXPECT_EQ(list->next->val, 4);
    EXPECT_EQ(list->next->next->val, 3);
    EXPECT_EQ(list->next->next->next->val, 2);
    EXPECT_EQ(list->next->next->next->next->val, 1);
    EXPECT_EQ(list->next->next->next->next->next, nullptr);
}

TEST(LinkList, reverseUsingRecursion) {
    Solution s;
    LinkList list;
    vector<int> t;


    s.vectorToLinkList(list, {1, 2, 3, 4, 5});
    EXPECT_EQ(list->val, 1);
    EXPECT_EQ(list->next->val, 2);
    EXPECT_EQ(list->next->next->val, 3);
    EXPECT_EQ(list->next->next->next->val, 4);
    EXPECT_EQ(list->next->next->next->next->val, 5);
    EXPECT_EQ(list->next->next->next->next->next, nullptr);
    LinkList rlist = s.reverseListWithRecursion(list);
    EXPECT_EQ(rlist->val, 5);
    EXPECT_EQ(rlist->next->val, 4);
    EXPECT_EQ(rlist->next->next->val, 3);
    EXPECT_EQ(rlist->next->next->next->val, 2);
    EXPECT_EQ(rlist->next->next->next->next->val, 1);
    EXPECT_EQ(rlist->next->next->next->next->next, nullptr);
}

TEST(LinkList, reverseUsingUnshift) {
    Solution s;
    LinkList list;
    vector<int> t;


    s.vectorToLinkList(list, {1, 2, 3, 4, 5});
    EXPECT_EQ(list->val, 1);
    EXPECT_EQ(list->next->val, 2);
    EXPECT_EQ(list->next->next->val, 3);
    EXPECT_EQ(list->next->next->next->val, 4);
    EXPECT_EQ(list->next->next->next->next->val, 5);
    EXPECT_EQ(list->next->next->next->next->next, nullptr);
    LinkList rlist = s.reverseListWithUnshift(list);
    EXPECT_EQ(rlist->val, 5);
    EXPECT_EQ(rlist->next->val, 4);
    EXPECT_EQ(rlist->next->next->val, 3);
    EXPECT_EQ(rlist->next->next->next->val, 2);
    EXPECT_EQ(rlist->next->next->next->next->val, 1);
    EXPECT_EQ(rlist->next->next->next->next->next, nullptr);
}
