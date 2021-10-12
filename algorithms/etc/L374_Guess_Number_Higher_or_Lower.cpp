/**
 * Leetcode 374) https://leetcode.com/problems/guess-number-higher-or-lower/
 * 
 * Guess Number Higher or Lower
 */

#include <iostream>

using namespace std;

int nPick;

int guess(int num) {
    return nPick < num ? -1 : nPick > num ? 1 : 0;
}

/* ----- Solution ----- */
class Solution {
public:
    int guessNumber(int n) {
        uint nBottom = 1, nTop = n;
        n = 1;
        while(n != 0) {
            n = guess((nTop + nBottom) / 2);
            if(n > 0) {
                nBottom = (nTop + nBottom) / 2 + 1;
            } else if(n < 0) {
                nTop = (nTop + nBottom) / 2 - 1;
            }
        }
        return (nTop + nBottom) / 2;
    }
};

/* ----- Testing ----- */
struct  Testing {
    int n;
    int pick;
    int out;
};

int main() {
    Testing t[4] = {
        Testing{10, 6, 6},
        Testing{1, 1, 1},
        Testing{2, 1, 1},
        Testing{2, 2, 2},
    };

    Solution s;
    for(const auto& tcase : t) {
        nPick = tcase.pick;
        if(s.guessNumber(tcase.n) != tcase.out) {
            cout << "FAIL" << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}