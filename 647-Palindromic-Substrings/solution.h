#ifndef SOLUTION_H__
#define SOLUTION_H__

#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    /**
     * should to use DP to save time; 
     */
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        
        int len = s.size(), count = 0;
        string substr;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j <= len - i; ++j) {
                substr = s.substr(j, i);
                if (isPalindromic(substr)) ++count;
            }    
        }
        return count;
    }
    
    bool isPalindromic(string &str) {
        int i = 0, j = str.size() - 1;
        while (i < j) {
            if (str[i++] != str[j--]) return false;
        }
        return true;
    }
};

#endif /* ifndef SOLUTION_H__ */
