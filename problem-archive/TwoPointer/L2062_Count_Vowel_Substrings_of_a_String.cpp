/**
 * Leetcode 2062) https://leetcode.com/problems/count-vowel-substrings-of-a-string/submissions/
 *
 * Count Vowel Substrings of a String
 */

#include <iostream>
#include <unordered_set>

using namespace std;

/* ----- Solution ----- */
class Solution {
    bool isVowel(const char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int countVowelSubstrings(string word) {
        int cnt = 0;
        unordered_set<char> s;
        for(size_t i = 0; i < word.size(); i++) {
            if(isVowel(word[i])) {
                s.clear();
                for(size_t j = i; j < word.size(); j++) {
                    if(isVowel(word[j])) {
                        s.insert(word[j]);
                        if(s.size() == 5) { cnt++; }
                    } else {
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};

/* ----- Testing ----- */
struct Testing {
    string inp;
    int outp;
};

const int TCASE_SIZE = 4;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{"aeiouu", 2},
        Testing{"unicornarihan", 0},
        Testing{"cuaieuouac", 7},
        Testing{"bbaeixoubb", 0}
    };

    Solution s;

    for(auto& tcase : t) {
        int res = s.countVowelSubstrings(tcase.inp);
        if(res != tcase.outp) {
            cout << "FAIL want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
