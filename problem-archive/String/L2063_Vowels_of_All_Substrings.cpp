/**
 * Leetcode 2063) https://leetcode.com/problems/vowels-of-all-substrings/
 *
 * Vowels of All Substrings
 */

#include <iostream>

/* ----- Solution ----- */
using namespace std;

class Solution {
public:
    long long countVowels(string word) {
        long long cnt = 0;
        for(size_t i = 0; i < word.size(); i++) {
            switch(word[i]) {
                case 'a': case 'e': case 'i': case 'o': case 'u':
                cnt += i + 1;
                cnt += word.size() - i - 1;
                cnt += i * (word.size() - i - 1);
            }
        }
        return cnt;
    }
};

/* ----- Testing ----- */
struct Testing {
    string inp;
    long long outp;
};

const int TCASE_SIZE = 4;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{"aba", 6},
        Testing{"abc", 3},
        Testing{"ltcd", 0},
        Testing{"noosabasboosa", 237}
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.countVowels(tcase.inp);
        if(res != tcase.outp) {
            cout << "FAIL want: " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}

