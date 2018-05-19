#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>

using std::vector;

class Solution {
public:

    int uniquePathsWithObstacles(const vector<vector<int>> &grid) {
        int m = grid.size();
        if (m > 0) {
            int n = grid[0].size();
            if (n > 0) {
                vector<vector<int>> ways(m, vector<int>(n, 0));
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (grid[i][j] == 0) {
                            if (j == i && i == 0) {
                                ways[0][0] = 1;
                            } else {
                                ways[i][j] += (i - 1) >= 0 ? ways[i - 1][j] : 0;
                                ways[i][j] += (j - 1) >= 0 ? ways[i][j - 1] : 0;
                            }
                        }
                    }
                }
                return ways[m - 1][n - 1];
            }
        }
        return 0;
    }
};

#endif
