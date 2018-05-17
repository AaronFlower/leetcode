#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <cstddef>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carrier = 0;
        ListNode *l3, *p3;
        l3 = p3 = NULL;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                sum = l1->val + l2 -> val + carrier;
            } else if (l1 != NULL) {
                sum = l1->val + carrier;
            } else {
                sum = l2->val + carrier;   
            }
            
            carrier = sum / 10;
            sum -= carrier * 10;
            
            ListNode *node = new ListNode(sum);
            if (!l3) {
                l3 = p3 = node;
            } else {
                p3->next = node;
                p3 = p3->next;
            }
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }  
        }

        if (carrier > 0) {
            ListNode *node = new ListNode(carrier);
            p3->next = node;
        }
        
        return l3;
    }
};

#endif
