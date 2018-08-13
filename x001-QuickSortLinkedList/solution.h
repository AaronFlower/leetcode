#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
#include <stack>

using std::vector;
using std::stack;

// add struct comment
struct ListNode {
    int val;
    ListNode * next;
    ListNode (int v) : val(v), next(nullptr) {}
};

using LinkList = ListNode *;

class Solution {
public:
    
    void quickSort(ListNode* begin, ListNode* end) {
        ListNode *mid = partition(begin, end);
        if (mid) {
            quickSort(begin, mid);
            quickSort(mid, end);
        }
    }

    ListNode* partition(ListNode* begin, ListNode* end) {
        if (begin && end) {
            ListNode dummy(-1);
            ListNode *pi, *pj;
            int pivot = begin->val;
            int tmp;
            dummy.next = begin;
            pi = &dummy;
            pj = begin;

            while (pj && pj != end) {
                if (pj->val < pivot) {
                    pi = pi->next; 
                    tmp = pi->val;
                    pi->val = pj->val;
                    pj->val = tmp;
                }      
                pj = pj->next;
            }
            return pi->next;
        }
        return nullptr;
    }

    ListNode* createList(const vector<int> &data) {
        ListNode dummy(-1);
        ListNode* head = &dummy;
        
        for (auto v:data) {
            head->next = new ListNode(v);
            head = head->next;
        }
        return dummy.next;
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

