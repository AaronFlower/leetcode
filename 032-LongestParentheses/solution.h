#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
#include <string>

using std::vector;
using std::string;
using std::max;

class Solution {
public:
    int longestValidParentheses(string str) {
        int curMax = 0;
        int n = str.size();
        vector<int> length(n, 0);
        
        for (int i = 1; i < n; ++i) {
            if (str[i] == ')') {
                if (str[i - 1] == '(') {
                    length[i] = 2 + ((i - 2) >= 0 ? length[i - 2] : 0);
                } else {
                    int k = i - length[i - 1];
                    if (k > 0 && str[k - 1] == '(') {
                        length[i] = 2 + length[i - 1] + ((k - 2) >= 0 ? length[k - 2] : 0);
                    }
                }
            }
            curMax = max(length[i], curMax);
        }
        return curMax;
    }
};

#endif
