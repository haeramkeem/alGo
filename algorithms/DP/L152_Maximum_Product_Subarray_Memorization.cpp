/**
 * Leetcode 152) https://leetcode.com/problems/maximum-product-subarray/
 *
 * Maximum Product Subarray
 *
 * DP: Memorization + Recursion
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
    vector<int> dpMin;
    vector<vector<int>> dpMax;
    int N;
public:
    int maxProduct(vector<int>& nums) {
        N = nums.size();
        dpMin.clear();
        dpMax.clear();

        if(N == 1) {
            return nums[0];
        }

        dpMin.resize(N, INT_MAX);
        dpMax.resize(N, vector<int>(2, INT_MIN));
        return max(
            maxProductImpl(nums, 0, 1),
            maxProductImpl(nums, 0, 0)
        );
    }

    int maxProductImpl(vector<int>& nums, const int& start, const int& pickStart) {
        if(start == N - 1) { return pickStart == 1 ? nums[start] : INT_MIN; }

        if(dpMax[start][pickStart] == INT_MIN) {
            if(pickStart == 1) {
                dpMax[start][pickStart] = max(nums[start], nums[start] * (
                    nums[start] < 0 ?
                    minProductImpl(nums, start + 1) :
                    maxProductImpl(nums, start + 1, 1)
                ));
            } else {
                dpMax[start][pickStart] = max(
                    maxProductImpl(nums, start + 1, 0),
                    maxProductImpl(nums, start + 1, 1)
                );
            }
        }

        return dpMax[start][pickStart];
    }

    int minProductImpl(vector<int>& nums, const int& start) {
        if(start == N - 1) { return nums[start]; }

        if(dpMin[start] == INT_MAX) {
            dpMin[start] = min(nums[start], nums[start] * (
                nums[start] < 0 ?
                maxProductImpl(nums, start + 1, 1) :
                minProductImpl(nums, start + 1)
            ));
        }

        return dpMin[start];
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums;
    int outp;
    Testing(): Testing({}, 0) {}
    Testing(vector<int> n, int o): nums(n), outp(o) {}
    const static int SIZE = 6;
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({2,3,-2,4}, 6),
        Testing({-2,0,-1},0),
        Testing({-2}, -2),
        Testing({-3,-1,-1}, 3),
        Testing({0,2}, 2),
        Testing({2,-5,-2,-4,3}, 24),
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
