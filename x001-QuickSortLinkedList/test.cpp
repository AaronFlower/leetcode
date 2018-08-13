#include "gtest/gtest.h"
#include "solution.h"

void checkList(LinkList list, const vector<int> &data) {
    int i = 0;
    ListNode *p = list;
    while (p) {
        EXPECT_EQ(p->val, data[i++]);
        p = p->next;
    }
}

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

    t = {1, 2, 3};
    LinkList list2 = s.createList(t);
    checkList(list2, t); 
}


TEST(LinkList, Partition) {
    Solution s;
    LinkList list;
    vector<int> t;

    t = {1, 2, 3, 4, 5};
    s.vectorToLinkList(list, t);
    checkList(list, t);


    LinkList list2;
    t = {2, 4, 1, 0, 6, 3};
    list2 = s.createList(t);
    checkList(list2, t);

    vector<int> partitionT = {7, 7, 7, 7, 7, 7, 7};
    ListNode* mid = s.partition(list2, nullptr);
    /* checkList(list2, partitionT); */
    checkList(mid, {2, 4, 7, 6});
}
