#ifndef GREEDY_SOLUTION_H_
#define GREEDY_SOLUTION_H_

#include<vector>

using std::vector;

class Solution {
    public: 
        using pos = size_t;
        bool checkIsSubsetSumRecursion(const vector<int> &arr, pos i, int total) {
            if (total == 0) return true;
            if (i == 0 && total != 0) return false;
            
            if (total < arr[i]) {
                // Only has one case. 
                return checkIsSubsetSumRecursion(arr, i - 1, total);
            } else {
                // Has two cases.
                return checkIsSubsetSumRecursion(arr, i - 1, total) || checkIsSubsetSumRecursion(arr, i - 1, total - arr[i]);
            }

            return true;
        }
};


#endif
