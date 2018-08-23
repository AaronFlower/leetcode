#ifndef LEET_CODE_KNIGHT_TOUR_H__
#define LEET_CODE_KNIGHT_TOUR_H__ 

#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::vector;
using std::set;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    void permute (string s) {
        set<string> trackSet;
       permuteHelper(s, "", trackSet); 
    }    

    void permuteHelper(string s, string chosen, set<string>& trackSet) {
        if (s.empty()) {
            if (trackSet.find(chosen) == trackSet.end()) {
                trackSet.insert(chosen);
                cout << chosen << endl; 
            }
        }

        for (size_t i = 0; i < s.length(); ++i) {
            // chose
            char c = s[i];
            chosen += c;
            s.erase(i, 1);
            
            // explore
            permuteHelper(s, chosen, trackSet);

            // unchosen
            chosen.erase(chosen.length() - 1, 1);
            s.insert(i, {c});
        }
    }
};
#endif /* ifndef LEET_CODE_KNIGHT_TOUR_H__ */
