#include "gtest/gtest.h"
#include "solution.h"

#include <vector>

using std::vector;
using std::cout;
using std::endl;

void checkList(ListNode* list, const vector<int>& data) {
    ListNode* p = list;
    int i = 0;
    while (p) {
        EXPECT_EQ(p->val, data[i++]);
        p = p->next;
    }
}

TEST(MergeTwoLists, ByDummyHead) {
    Solution s;
    ListNode* list1, * list2;
    s.createLinkList(list1, {1, 2, 4});
    EXPECT_EQ(1, list1->val);
    EXPECT_EQ(2, list1->next->val);
    EXPECT_EQ(4, list1->next->next->val);
    EXPECT_EQ(nullptr, list1->next->next->next);

    s.createLinkList(list2, {1, 3, 4});
    EXPECT_EQ(1, list2->val);
    EXPECT_EQ(3, list2->next->val);
    EXPECT_EQ(4, list2->next->next->val);
    EXPECT_EQ(nullptr, list2->next->next->next);

    vector<int> data = {1, 1, 2, 3, 4, 4};
    ListNode* newList = s.mergeTwoLists(list1, list2);
    checkList(newList, data);
    s.destroyLinkList(newList);
    
    s.createLinkList(list1, {1});
    s.createLinkList(list2, {1, 2, 3});
    newList = s.mergeTwoLists(list1, list2);
    checkList(newList, {1, 1, 2, 3});
    s.destroyLinkList(newList);

    s.createLinkList(list1, {1, 2, 3});
    s.createLinkList(list2, {1});
    newList = s.mergeTwoLists(list1, list2);
    checkList(newList, {1, 1, 2, 3});
    s.destroyLinkList(newList);
}

TEST(MergeKLists, DivideAndConquer) {
    ListNode *l1, *l2, *l3, *l4, *l5, *l6;
    Solution s;
    vector<ListNode*> lists;
    s.createLinkList(l1, {1, 2, 3});
    s.createLinkList(l2, {1, 4, 6});
    s.createLinkList(l3, {1, 2, 3});
    s.createLinkList(l4, {1, 4, 6});
    s.createLinkList(l5, {1, 2, 3});
    s.createLinkList(l6, {1, 4, 6});
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    lists.push_back(l4);
    lists.push_back(l5);
    lists.push_back(l6);
    
    vector<int> data;
    ListNode* newList = s.mergeKLists(lists); 
    ListNode* p = newList;
    while (p) {
        cout << p->val << "\t";
        p = p->next;
    }
}


TEST(MergeKLists, FromFront) {
    ListNode *l1, *l2, *l3, *l4, *l5, *l6;
    Solution s;
    vector<ListNode*> lists;
    s.createLinkList(l1, {1, 2, 3});
    s.createLinkList(l2, {1, 4, 6});
    s.createLinkList(l3, {1, 2, 3});
    s.createLinkList(l4, {1, 4, 6});
    s.createLinkList(l5, {1, 2, 3});
    s.createLinkList(l6, {1, 4, 6});
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    lists.push_back(l4);
    lists.push_back(l5);
    lists.push_back(l6);
    
    vector<int> data;
    ListNode* newList = s.mergeKListsFront(lists); 
    ListNode* p = newList;
    while (p) {
        cout << p->val << "\t";
        p = p->next;
    }
}

