#include "gtest/gtest.h"
#include "solution.h"

using LinkList = Solution::LinkList;

void checkListEqual(LinkList list, vector<int> data) {
    int i = 0;
    ListNode *p = list;
    while (p) {
        EXPECT_EQ(p->val, data[i ++]);
        p = p->next;
    }
    EXPECT_EQ(i, data.size());
}

TEST(LinkList, create) {
    Solution s;
    LinkList list;
    vector<int> data{1, 2, 3, 4, 5};
    s.createList(list, data);
    checkListEqual(list, data);
}


TEST(LinkList, reverse) {
    Solution s;
    LinkList list;
    vector<int> data{1, 2, 3, 4, 5};
    s.createList(list, data);
    checkListEqual(list, data);
    LinkList rlist = s.reverse(list);
    checkListEqual(rlist, {5, 4, 3, 2, 1});
}

TEST(LinkList, reverseBetween) {
    Solution s;
    LinkList list, rlist;
    vector<int> data{1, 2};
    s.createList(list, data);
    checkListEqual(list, data);
    rlist = s.reverseBetween(list, 1, 2);
    checkListEqual(rlist, {2, 1});

    data = {1, 2, 3, 4, 5};
    s.createList(list, data);
    checkListEqual(list, data);
    std::reverse(std::begin(data), std::end(data));
    rlist = s.reverseBetween(list, 1, 5);
    checkListEqual(rlist, data);

    data = {1, 2, 3, 4, 5};
    s.createList(list, data);
    checkListEqual(list, data);
    std::reverse(std::begin(data) + 1, std::end(data) - 1);
    rlist = s.reverseBetween(list, 2, 4);
    checkListEqual(rlist, data);
}
