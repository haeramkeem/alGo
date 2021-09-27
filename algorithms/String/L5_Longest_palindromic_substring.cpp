/**
 * Leetcode 5
 * 
 * Longest Palindromic Substring
 */

#include <iostream>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) { return s; }
        string strMax = "";
        for(auto it = s.begin(); it < s.end(); it++) {
            if(it + 2 < s.end() && *it == *(it + 2)) {
                auto l = it, r = it + 2;
                while(s.begin() <= l && r < s.end() && *l == *r) { l--;r++; }
                strMax = strMax.size() < r - l - 1 ? s.substr(l - s.begin() + 1, r - l - 1) : strMax;
            }
            if(it + 1 < s.end() && *it == *(it + 1)) {
                auto l = it, r = it + 1;
                while(s.begin() <= l && r < s.end() && *l == *r) { l--;r++; }
                strMax = strMax.size() < r - l - 1 ? s.substr(l - s.begin() + 1, r - l - 1) : strMax;
            }
        }
        return strMax == "" ? string({s[0]}) : strMax;
    }
};

/* ----- Testing ----- */
struct Testing {
    string strInput;
    string strOutput;
};

int main() {
    Testing t[7] = {
        Testing{"babad", "bab"},
        Testing{"cbbd", "bb"},
        Testing{"ac", "a"},
        Testing{"a", "a"},
        Testing{"bb", "bb"},
        Testing{"aaaa", "aaaa"},
        Testing{"abbcccbbbcaaccbababcbcabca", "bbcccbb"},
    };

    Solution s;
    for(auto el : t) {
        string strRes = s.longestPalindrome(el.strInput);
        cout<< el.strInput << ' '
            << strRes << ' '
            << boolalpha << (strRes == el.strOutput) << endl;
    }
}
