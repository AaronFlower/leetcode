#ifndef GREEDY_SOLUTION_H_
#define GREEDY_SOLUTION_H_

#include<vector>
#include<string>
#include<unordered_map>

using std::vector;
using std::unordered_map;
using std::string;
using std::to_string;

class Solution {
    public: 
        using pos = size_t;
        using umap = unordered_map<string, bool>;

        bool checkIsSubsetSum(const vector<int> &arr, pos n, int total) {
            bool mem[n + 1][total + 1];
            for (size_t  i = 0; i < n + 1; ++i) {
                mem[i][0] = true;
            } 

            for (int t = 1; t < total + 1; ++t) {
                mem[0][t] = false;
            }

            for (size_t i = 1; i < n + 1; ++i) {
                for (int j = 1; j < total + 1; ++j) {
                    if (j < arr[i - 1]) {
                        mem[i][j] = mem[i - 1][j];
                    } else {
                        mem[i][j] = mem[i - 1][j] || mem[i - 1][j - arr[i - 1]];
                    }
                }
            }
            return mem[n][total];
        }

        bool checkIsSubsetSumRecursion(const vector<int> &arr, pos i, int total) {
            if (total == 0) return true;
            if (i == 0 && total != 0) return false;
            
            if (arr[i - 1] > total) {
                // Only has one case. 
                return checkIsSubsetSumRecursion(arr, i - 1, total);
            } else {
                // Has two cases.
                return checkIsSubsetSumRecursion(arr, i - 1, total) || 
                    checkIsSubsetSumRecursion(arr, i - 1, total - arr[i - 1]);
            }
            return true;
        }

        bool checkIsSubsetSumMem(const vector<int> &arr, pos i, int total, umap &mem) {
            string key = to_string(i - 1) + "|" + to_string(total); 
            auto search = mem.find(key);
            if (search != mem.end()) {
                return search->second;
            }
            if (total == 0) return true;
            if (i == 0 && total != 0) return false;
            bool ret;
            if (arr[i - 1] > total) {
                // Only has one case. 
                ret = checkIsSubsetSumMem(arr, i - 1, total, mem);
            } else {
                // Has two cases.
                ret = checkIsSubsetSumMem(arr, i - 1, total, mem) ||
                    checkIsSubsetSumMem(arr, i - 1, total - arr[i - 1], mem);
            }
            mem.insert(std::make_pair(key, ret));
            return ret;
        }

};


#endif
