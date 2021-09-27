/**
 * Leetcode 242
 * 
 * Valid Anagram
 * 
 * ref: map comparison
 */

#include <iostream>
#include <map>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mapS, mapT;
        for(auto el : s) {
            mapS[el]++;
        }
        for(auto el : t) {
            mapT[el]++;
        }
        return mapS == mapT;
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