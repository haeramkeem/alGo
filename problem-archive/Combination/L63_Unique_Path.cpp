/**
 * Leetcode 62) https://leetcode.com/problems/unique-paths/
 *
 * Unique Path
 *
 * Combination: mCn
 */

#include <iostream>

using namespace std;
#define ll long long

/* ----- Solution ----- */
class Solution {
public:
    int uniquePaths(int m, int n) {
        m--; n--;
        ll res = m + n;
        int cnt = min(m, n);
        if(cnt == 0) { return 1; }
        if(cnt == 1) { return res; }
        for(int i = 1; i < cnt; i++) {
            res *= m + n - i;
        }
        for(int i = cnt; i > 0; i--) {
            res /= i;
        }
        return res;
    }
};

/* ----- Testing ----- */
struct Testing {
    int m, n, outp;
};

const int TCASE_SIZE = 3;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{3, 2, 3},
        Testing{3, 7, 28},
        Testing{3, 3, 6},
    };

    Solution s;

    for(const auto& tcase : t) {
        int res = s.uniquePaths(tcase.m, tcase.n);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
