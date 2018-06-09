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

TEST(LinkListIntersection, getIntersectionNode) {
    Solution s;
    LinkList list1, list2, list3;
    vector<int> data;
    
    s.vectorToLinkList(list1, {1, 3, 4});
    s.vectorToLinkList(list2, {5, 4});
    s.vectorToLinkList(list3, {7, 7});
    list2->next->next = list1;
    list3->next->next = list1;

    EXPECT_EQ(s.getIntersectionNode(list2, list3), list1);
    EXPECT_EQ(s.getIntersectionNode(list1, nullptr), nullptr);
}
