/**
 * L279) https://leetcode.com/problems/perfect-squares/
 * 
 * Perfect Squares
 */

#include <iostream>
#include <cmath>

using namespace std;

/* ----- Solution ----- */
class Solution {
    int dp[10000] = {};
public:
    int numSquares(int n) {
        if(dp[n - 1] != 0) {
            return dp[n - 1];
        }
        int sRoot = sqrt(n), nMin = INT_MAX;
        if(n == sRoot * sRoot) {
            dp[n - 1] = 1;
            return 1;
        }
        for(int i = sRoot; i > 0; i--) {
            nMin = min(nMin, numSquares(n - i * i) + 1);
        }
        dp[n - 1] = nMin;
        return nMin;
    }
};

/* ----- Testing ----- */
struct Testing {
    int nIn;
    int nOut;
};

const int TCASE_SIZE = 3;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{12, 3},
        Testing{13, 2},
        Testing{62, 3},
    };

    Solution s;

    for(const auto& tcase : t) {
        int res = s.numSquares(tcase.nIn);
        if(tcase.nOut != res) {
            cout << "FAIL: want " << tcase.nOut << ", got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}