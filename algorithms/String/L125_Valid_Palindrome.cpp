/**
 * Leetcode 125
 * 
 * Valid Palindrome
 */

#include <iostream>
#include <regex>
#include <algorithm>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    bool isPalindrome(string s) {
        regex re("[^a-zA-Z0-9]");
        string strRefined = regex_replace(s, re, "");
        transform(strRefined.begin(), strRefined.end(), strRefined.begin(), ::tolower);
        auto l = strRefined.begin(), r = strRefined.end() - 1;
        while(l < r) {
            if(*l != *r) { return false; }
            l++; r--;
        }
        return true;
    }
};

/* ----- Testing ----- */
struct Testing {
    string strInput;
    bool bOutput;
};

int main() {
    Testing t[2] = {
        Testing{"A man, a plan, a canal: Panama", true},
        Testing{"race a car", false},
    };

    Solution s;
    for(auto el : t) {
        cout<< el.strInput << ' '
            << boolalpha << (s.isPalindrome(el.strInput) == el.bOutput) << endl;
    }
}