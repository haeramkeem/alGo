/**
 * Leetcode 1413) https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
 *
 * Minimum Value to Get Positive Step by Step Sum
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 1, acc = 1;
        for(const auto& num : nums) {
            acc += num;
            if(acc < 1) {
                res += 1 - acc;
                acc = 1;
            }
        }
        return res;
    }
};

/* ----- Testing ----- */
struct Testing {

    vector<int> nums;
    int outp;
};

const int TCASE_SIZE = 3;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{{-3,2,-3,4,2}, 5},
        Testing{{1,2}, 1},
        Testing{{1,-2,-3}, 5},
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.minStartValue(tcase.nums);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
        }
    }

    cout << "ok" << endl;

    return 0;
}
