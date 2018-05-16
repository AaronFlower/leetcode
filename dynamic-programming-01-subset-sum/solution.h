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
        bool checkIsSubsetSumRecursion(const vector<int> &arr, pos i, int total) {
            if (total == 0) return true;
            if (i == 0 && total != 0) return false;
            
            if (arr[i - 1] > total) {
                // Only has one case. 
                return checkIsSubsetSumRecursion(arr, i - 1, total);
            } else {
                // Has two cases.
                return checkIsSubsetSumRecursion(arr, i - 1, total) || checkIsSubsetSumRecursion(arr, i - 1, total - arr[i - 1]);
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
                ret = checkIsSubsetSumMem(arr, i - 1, total, mem) || checkIsSubsetSumMem(arr, i - 1, total - arr[i - 1], mem);
            }
            mem.insert(std::make_pair(key, ret));
            return ret;
        }

};


#endif
