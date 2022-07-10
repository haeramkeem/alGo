/**
 * Leetcode 1178) https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
 *
 * Number of Valid Words for Each Puzzle
 *
 * Bit manipulate version
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int W = words.size(), P = puzzles.size();
        vector<int> res(P, 0);

        array<vector<int>, 26> intWords;
        for(const auto& word : words) {
            int intWord{};
            for(const auto& ch : word) {
                intWord |= 1 << (ch - 'a');
            }
            for(int i = 0; i < 26; i++) {
                if(intWord & 1 << i) {
                    intWords[i].push_back(intWord);
                }
            }
        }
        
        for(int i = 0; i < P; i++) {
            int cnt = 0;
            int intPuzz{};
            for(const auto& ch : puzzles[i]) {
                intPuzz |= 1 << (ch - 'a');
            }
            for(const auto& intWord : intWords[puzzles[i][0] - 'a']) {
                cnt += (intPuzz & intWord) == intWord ? 1 : 0;
            }
            res[i] = cnt;
        }
        
        return res;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<string> words;
    vector<string> puzzles;
    vector<int> outp;
};

const int TCASE_SIZE = 2;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{
            {"aaaa","asas","able","ability","actt","actor","access"},
            {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"},
            {1,1,3,2,4,0}
        },
        Testing{
            {"apple","pleas","please"},
            {"aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"},
            {0,1,3,2,0},
        },
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.findNumOfValidWords(tcase.words, tcase.puzzles);
        if(res != tcase.outp) {
            cout << "FAIL: want {";
            for(const auto& el : tcase.outp) {
                cout << el << ' ';
            }
            cout << "} got {";
            for(const auto& el : res) {
                cout << el << ' ';
            }
            cout << "}\n";
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
