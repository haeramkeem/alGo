/**
 * Leetcode 96) https://leetcode.com/problems/unique-binary-search-trees/
 *
 * Unique Binary Search Trees
 */

#include <iostream>

using namespace std;

/* ----- Solution ----- */
class Solution {
    int dp[20] = {};
public:
    Solution() {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
    }
    int numTrees(int n) {
        if(dp[n] != 0) { return dp[n]; }
        for(int i = 3; i <= n; i++) {
            dp[i] = 2 * dp[i - 1];
            for(int j = 1; j < i - 1; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};

/* ----- Testing ----- */
struct Testing {
    int inp;
    int outp;
};

const int TCASE_SIZE = 5;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{1, 1},
        Testing{2, 2},
        Testing{3, 5},
        Testing{4, 14},
        Testing{5, 42},
    };

    Solution s;

    for(auto& tcase : t) {
        int res = s.numTrees(tcase.inp);
        if(res != tcase.outp) {
            cout << "FAIL want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
