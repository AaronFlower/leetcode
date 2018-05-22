#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>

using std::vector;
using std::min;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> mini = triangle[m - 1];

        for (int i = m - 2; i >= 0; --i) {
            for(size_t j = 0; j < triangle[i].size(); ++j) {
                mini[j] = triangle[i][j] + min(mini[j], mini[j + 1]);                
            }
        }
        return mini[0];
    }
};

#endif

