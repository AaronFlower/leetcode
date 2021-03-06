#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct ListNode {
    int val;
    ListNode * next;
    ListNode (int v) : val(v), next(nullptr) {}
};

using LinkList = ListNode *;

class Solution {
public:
    ListNode* reverseListWithRecursion(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode * rhead = reverseListWithRecursion(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rhead;
    }

    ListNode* reverseListWithUnshift(ListNode* head) {
        ListNode *pre = nullptr;
        while (head) {
            ListNode *tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp; 
        }
        return pre;
    }

    /** use reference to save memeory copy **/
    ListNode* reverseListWithStack(ListNode* &head) {
        if (head) {
            ListNode * p = head;
            stack<int> q;
            while (p) {
                q.push(p->val);
                p = p ->next;
            }
            p = head;
            int top;
            while (p) {
                top = q.top();
                p->val = top;
                p = p->next;
                q.pop();
            }
        }   
        return head;
    }

    void vectorToLinkList(ListNode* &head, vector<int> data) {
        ListNode *p;
        head = nullptr;

        for (auto v: data) {
            if (head == nullptr) {
                head = new ListNode(v);
                p = head;
            } else {
                p->next = new ListNode(v);
                p = p->next;
            }
        }
    }
};

#endif

