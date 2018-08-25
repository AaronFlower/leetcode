#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <string>
using std::string;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchHelper(s, p);   
    }
    
private:
    bool matchEmpty (string p) {
      if (p.size() % 2) {
        return false;
      }
      for (size_t i = 1; i < p.size(); i += 2) {
        if (p[i] != '*') return false;
      }
      return true;
    }

    bool isMatchHelper(string &s, string &p) {
        if (s.empty() || p.empty()) {
            return (s.empty() && p.empty()) || (s.empty() && matchEmpty(p));
        }
        try {
            // case for slice one character
            string pSub = p.substr(0, 1);
            string sSub = s.substr(0, 1);
            if (pSub == "." || pSub == sSub) {
                s.erase(0, 1);
                p.erase(0, 1);
                if (isMatchHelper(s, p)) return true;
                s.insert(0, sSub);
                p.insert(0, pSub);
            }
            // case for two character
            pSub = p.substr(0, 2);
            char p1 = pSub[0];
            char p2 = pSub[1];
            
            if (p2 == '*') {
                if (p1 == '.') {
                    for (size_t si = 0; si <= s.size(); ++si) {
                        string sEraseStr = s.substr(0, si);
                        s.erase(0, 0 + si);
                        p.erase(0, 2);
                        if (isMatchHelper(s, p)) return true;
                        s.insert(0, sEraseStr);
                        p.insert(0, pSub);
                    }
                    
                } else {
                    size_t nextPos = s.size();
                    for (size_t si = 0; si < s.size(); ++si) {
                        if (s[si] != p1) {
                            nextPos = si;
                            break;
                        }
                    }
                  
                  for (size_t si = 0; si <= nextPos; ++ si) {
                    string sEraseStr = s.substr(0, si);
                    s.erase(0, 0 + si);
                    p.erase(0, 2);
                    if (isMatchHelper(s, p)) return true;
                    s.insert(0, sEraseStr);
                    p.insert(0, pSub);
                  }
                }
            }
        } catch (const std::out_of_range& e) {
            
        }
        return false;
    }
};
#endif
