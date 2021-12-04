/**
 * Leetcode 152) https://leetcode.com/problems/maximum-product-subarray/
 *
 * Maximum Product Subarray
 *
 * DP: Tabulation + Loop
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();

        vector<int> dpMin(N, INT_MAX);
        vector<vector<int>> dpMax(N, vector<int>(2, INT_MIN));
        dpMin[0] = nums[0];
        dpMax[0][1] = nums[0];

        int res = nums[0];
        for(size_t i = 1; i < nums.size(); i++) {
            dpMax[i][0] = max(dpMax[i - 1][0], dpMax[i - 1][1]);
            dpMax[i][1] = max(nums[i], nums[i] * (nums[i] < 0 ? dpMin[i - 1] : dpMax[i - 1][1]));
            dpMin[i] = min(nums[i], nums[i] * (nums[i] < 0 ? dpMax[i - 1][1] : dpMin[i  -1]));
            res = max(res, max(dpMax[i][0], dpMax[i][1]));
        }

        return res;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums;
    int outp;
    Testing(): Testing({}, 0) {}
    Testing(vector<int> n, int o): nums(n), outp(o) {}
    const static int SIZE = 7;
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({2,3,-2,4}, 6),
        Testing({-2,0,-1},0),
        Testing({-2}, -2),
        Testing({-3,-1,-1}, 3),
        Testing({0,2}, 2),
        Testing({2,-5,-2,-4,3}, 24),
        Testing({-1,-2,-9,-6}, 108),
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.maxProduct(tcase.nums);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
