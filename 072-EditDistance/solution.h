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
        int m = word1.size() + 1;
        int n = word2.size() + 1;
        vector<vector<int>> dist(m, vector<int>(n, 0));

        for (int j = 0; j < m; ++j) dist[j][0] = j;
        for (int i = 0; i < n; ++i) dist[0][i] = i;
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dist[i][j] = dist[i - 1][j - 1];
                } else {
                    dist[i][j] = 1 + min(dist[i - 1][j - 1], min(dist[i - 1][j], dist[i][j - 1]));
                }
            }
        }
        return dist[m - 1][n - 1]; 
    }

    int minDistance2(const string &x, const string &y) {
        int m = x.size();
        int n = y.size();
        
        if (m == 0 || n == 0) {
            return m != 0 ? m : n;
        }
        
        vector<vector<int>> dist(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++ j) {
                if (i == 0 && j == 0) {
                    dist[i][j] = x[i] == y[j] ? 0 : 1;
                } else {
                    dist[i][j] = x[i] == y[j] ? 0 : 1;
                    dist[i][j] += 
                        min(
                            (i - 1) >= 0 ? dist[i - 1][j] : INFINITY, 
                            min(
                                (j - 1) >= 0 ? dist[i][j - 1] : INFINITY, 
                                (i - 1) >= 0  && (j - 1) >= 0 ? dist[i - 1][j - 1] : INFINITY
                            )
                        );   
                }
            }
        }
        return dist[m - 1][n - 1];
    }

    int minDistance3(string x, string y) {
        int m = x.size();
        int n = y.size();
        
        if (m == 0 || n == 0) {
            return m != 0 ? m : n;
        }
        
        vector<vector<int>> dist(m, vector<int>(n, 0));
        
        if (x[0] != y[0]) dist[0][0] = 1;
        
        for (int i = 1; i < m; ++i) {
            dist[i][0] = (y[0] == x[i] ? 0 : 1) + dist[i - 1][0]; 
        }
        
        for (int j = 1; j < n; ++j) {
            dist[0][j] = (x[0] == y[j] ? 0 : 1) + dist[0][j - 1]; 
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++ j) {
                dist[i][j] = (x[i] == y[j] ? 0 : 1) + 
                    min(
                        dist[i - 1][j - 1], 
                        min(
                            dist[i - 1][j], 
                            dist[i][j - 1]
                        )
                    );    
            }
        }

        for (int i = 0; i < m; ++i ) {
            for (int j = 0; j < n; ++j) {
                std::cout << dist[i][j] << "\t";
            }
            std::cout<< std::endl;
        }
        std::cout<<std::endl;
        return dist[m - 1][n - 1];
    }
};
#endif
