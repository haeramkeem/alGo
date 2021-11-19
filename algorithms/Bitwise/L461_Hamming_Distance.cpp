/**
 * Leetcode 461) https://leetcode.com/problems/hamming-distance/
 *
 * Hamming Distance
 */

#include <iostream>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for(int b = 0; b < 32; b++) {
            if((x & (1 << b)) != (y & (1 << b))) {
                res++;
            }
        }
        return res;
    }
};

/* ----- Testing ----- */
struct Testing {
    int x, y, outp;
};

const int TCASE_SIZE = 2;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{1, 4, 2},
        Testing{3, 1, 1},
    };

    Solution s;
    for(const auto& tcase : t) {
        int res = s.hammingDistance(tcase.x, tcase.y);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
