#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>

using std::vector;
using std::min;

class Solution {
public:

    int minPathSum(const vector<vector<int>> &grid) {
        int m = grid.size();
        if (m > 0) {
            int n = grid[0].size();
            if (n > 0) {
                vector<vector<int>> sum(m, vector<int>(n, 0));
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j ) {
                        if (i == 0 && j == 0) {
                            sum[i][j] = grid[0][0];
                        } else {
                            if (i - 1 < 0) {
                                sum[i][j] = grid[i][j] + sum[i][j - 1];
                            } else if( j - 1 < 0) {
                                sum[i][j] = grid[i][j] + sum[i - 1][j];
                            } else {
                                sum[i][j] = grid[i][j] + min(sum[i -1][j], sum[i][j - 1]);
                            }
                        }
                    }
                }
                return sum[m - 1][n - 1];
            }
        }    
        return 0;
    }
};

#endif
