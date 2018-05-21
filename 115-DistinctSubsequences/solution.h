#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int numDistinctRecursive(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        if (m == 0 || n == 0) {
            return n == 0 ? 1 : 0;
        }
        if (s[0] == t[0]) {
            return numDistinctRecursive(s.substr(1, m), t.substr(1, n)) +
                numDistinctRecursive(s.substr(1, m), t);
        } else {
            return numDistinctRecursive(s.substr(1, m), t);
        }    
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> count(n+1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; ++j) count[0][j] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if (s[j - 1] == t[i - 1]) {
                    count[i][j] = count[i - 1][j - 1] + count[i][j - 1];
                } else {
                    count[i][j] = count[i][j - 1];
                }
            }
        }
        return count[n][m];
    }

};

#endif
