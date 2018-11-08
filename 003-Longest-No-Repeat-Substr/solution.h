#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <string>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, cur = 0, len = s.length();
        size_t fpos, startPos = 0;
        
        for (int i = 0; i < len; ++i) {
            string substr = s.substr(startPos, i);
            fpos = substr.find(s[i]);
            if (fpos == string::npos) {
                ++cur;    
            } else {
                max = max < cur ? cur : max;
                cur = i - fpos;
                startPos = (i + fpos + 1);
            }
        }
        return max > cur ? max : cur;
    }
};

#endif
