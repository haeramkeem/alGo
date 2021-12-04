/**
 * Leetcode 198) https://leetcode.com/problems/house-robber/
 *
 * House Robber
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
    int N;
    vector<int> dp;
    int robImpl(const vector<int>& nums, const int& start) {
        if(start == N - 1) {
            return nums[start];
        } else if(start >= N) {
            return 0;
        } else if(dp[start] != INT_MIN) {
            return dp[start];
        }
        return dp[start] = max(robImpl(nums, start + 2) + nums[start], robImpl(nums, start + 3) + nums[start + 1]);
    }
public:
    int rob(vector<int>& nums) {
        N = nums.size();
        dp.clear();
        dp.resize(N, INT_MIN);
        return robImpl(nums, 0);
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums;
    int outp;
    Testing(): Testing({}, 0) {}
    Testing(vector<int> n, int o): nums(n), outp(o) {}
    static const int SIZE = 3;
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({1,2,3,1}, 4),
        Testing({2,7,9,3,1}, 12),
    };

    Solution s;
    for(auto& tcase : t) {
        auto res = s.rob(tcase.nums);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
