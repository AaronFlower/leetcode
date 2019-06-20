#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;
using std::greater;

class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int len = len1 + len2;
        bool isOdd = len % 2 != 0;
        int midLen = len / 2 +  1;

        priority_queue<int, vector<int>, greater<int>> q;


        for (auto n:nums1) {
            q.push(n);
            if (q.size() > midLen) {
                q.pop();
            }
        }

        for (auto n:nums2) {
            q.push(n);
            if (q.size() > midLen) {
                q.pop();
            }
        }

        if (isOdd) {
            return q.top();
        } else {
            int a = q.top();
            q.pop();
            return (a + q.top()) / 2.0;
        }
    }
};

#endif
