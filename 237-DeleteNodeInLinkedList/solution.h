#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
using std::vector;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v):val(v), next(nullptr){}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node != nullptr && node->next != nullptr) {
            ListNode *dp = node->next;
            node->val = node->next->val;
            node->next = node->next->next;
            delete dp; // in case of memory leak
        }
    }
    void createLinkList(ListNode* & list,  vector<int> data) {
        ListNode *p;
        list = nullptr;
        for (auto val : data) {
            if (list == nullptr) {
                list = new ListNode(val);
                p = list;
            } else {
                p->next = new ListNode(val);
                p = p->next;
            } 
        }
    }
};
#endif

