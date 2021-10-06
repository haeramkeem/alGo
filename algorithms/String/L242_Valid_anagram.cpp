/**
 * Leetcode 242
 * 
 * Valid Anagram
 * 
 * ref: map comparison
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vecS(26), vecT(26);
        for(const auto& ch : s) {
            vecS[ch - 'a']++;
        }
        for(const auto& ch : t) {
            vecT[ch - 'a']++;
        }
        return vecS == vecT;
    }
};

/* ----- Testing ----- */
struct Testing {
    string strInput1, strInput2;
    bool bOutput;
};

int main() {
    Testing t[5] = {
        Testing{"anagram", "nagaram", true},
        Testing{"rat", "car", false},
        Testing{"abcd", "dcba", true},
        Testing{"heart", "earth", true},
        Testing{"python", "typhon", true},
    };

    Solution s;
    for(auto el : t) {
        cout<< el.strInput1 << ' '
            << el.strInput2 << ' '
            << boolalpha << (s.isAnagram(el.strInput1, el.strInput2) == el.bOutput) << endl;
    }
}