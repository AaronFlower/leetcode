#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

struct Subset {
    int parent;
    int rank;
    Subset():parent(0),rank(0){}
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int M = grid.size();
        if (M == 0) return 0;
        int N = grid[0].size();
        if (N == 0) return 0;
        int shape= N * M;
        int parent[shape];
        int dirX[] = {0, 0, -1, 1};
        int dirY[] = {1, -1, 0, 0};

        printParent(parent, shape);
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int idx = i * N + j;
                if (grid[i][j] == '1') {
                    parent[idx] = idx;
                } else {
                    parent[idx] = -1;
                }
            }
        }

        printParent(parent, shape);

        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '1') {
                    int x = parent[i * N + j];
                    while (x != parent[x]) x = parent[x];
                    for (int k = 0; k < 4; ++k) {
                        int newI = i + dirX[k];
                        int newJ = j + dirY[k];
                        if (newI >= 0 && newI < M && newJ >= 0 && newJ < N && grid[newI][newJ] == '1') {
                            int y = newI * N + newJ;
                            while (y != parent[y]) y = parent[y];

                            if (x != y) {
                                parent[x] = y;
                                x = y;
                            }
                        }
                    }
                }
            }
        }
        
        printParent(parent, shape);

        int count = 0;
        for (int i = 0; i < shape; ++i) {
            if (parent[i] == i) {
                ++count;
            }
        }        
        return count;
    }

    void printParent (int* a, int n) {
        cout << "Parent " << endl;
        for (int i = 0; i < n; ++i ) {
            if (i % 5 == 0) cout << endl;
            cout << a[i] << "\t";
        }
        cout << endl;
    }

    int numIslandsByUnionRank(vector<vector<char>>& grid) {
        int M = grid.size();
        if (M == 0) return 0;
        int N = grid[0].size();
        if (N == 0) return 0;
        
        int shape= N * M;
        Subset subsets[shape];
        int dirX[] = {0, 0, -1, 1};
        int dirY[] = {1, -1, 0, 0};
        int count = 0;
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int idx = i * N + j;
                if (grid[i][j] == '1') {
                    subsets[idx].parent = idx;
                    ++count;
                } else {
                    subsets[idx].parent = -1;
                }
            }
        }
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '1') {
                    int x = find(subsets, i * N + j);
                    for (int k = 0; k < 4; ++k) {
                        int newI = i + dirX[k];
                        int newJ = j + dirY[k];
                        if (newI >= 0 && newI < M && newJ >= 0 && newJ < N && grid[newI][newJ] == '1') {
                            x = find(subsets, x);
                            int y = find(subsets, newI * N + newJ);
                            
                            if (x != y) {
                                unionSubset(subsets, x, y);
                                --count;
                            }
                        }
                    }
                }
            }
        }
              
        return count;
    }
private:
    int find(Subset* subsets, int i) {
        if (subsets[i].parent == i) return i;
        return find(subsets, subsets[i].parent);
    }
    
    void unionSubset(Subset* subsets, int i, int j) {
        if (subsets[i].rank == subsets[j].rank) {
            subsets[i].parent = j;
            subsets[j].rank++;
        } else if (subsets[i].rank < subsets[j].rank) {
            subsets[i].parent = j;
        } else {
            subsets[j].parent = i;
        }
    } 
};


#endif

