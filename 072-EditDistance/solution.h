#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using std::vector;
using std::string;
using std::min;

class Solution {
public:

    int minDistance(const string &word1, const string &word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dist(m + 1, vector<int>(n + 1, 0));

        for (int j = 0; j <= m; ++j) dist[j][0] = j;
        for (int i = 0; i <= n; ++i) dist[0][i] = i;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dist[i][j] = dist[i - 1][j - 1];
                } else {
                    dist[i][j] = 1 + min(dist[i - 1][j - 1], min(dist[i - 1][j], dist[i][j - 1]));
                }
            }
        }
        return dist[m][n]; 
    }


    int minDistanceColumn(const string &word1, const string &word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int> col(m + 1, 0);

        for (int i = 0; i <= m; ++i) col[i] = i;

        for (int j = 1; j <= n; ++j) {
            int pre = col[0];
            col[0] = j;

            for (int i = 1; i <= m; ++i) {
                int temp = col[i];
                if (word1[i - 1] == word2[j - 1]) {
                    col[i] = pre;
                } else {
                    col[i] = 1 + min(pre, min(col[i - 1], col[i]));
                }
                pre = temp;
            }
        }

        return col[m];
    }

    int minDistanceRow(const string &word1, const string &word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int> row(n + 1, 0);

        for (int j = 0; j <= n; ++j) row[j] = j;

        for (int i = 1; i <= m; ++i) {
            int pre = row[0];
            row[0] = i;

            for (int j = 1; j <= n; ++j) {
                int temp = row[j];
                if (word1[i - 1] == word2[j - 1]) {
                    row[j] = pre;
                } else {
                    row[j] = 1 + min(pre, min(row[j - 1], row[j]));
                }
                pre = temp;
            }
        }

        return row[n];
    }

};

#endif
