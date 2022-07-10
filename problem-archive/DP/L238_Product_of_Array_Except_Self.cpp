/**
 * Leetcode 238) https://leetcode.com/problems/product-of-array-except-self/
 *
 * Product of Array Except Self
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();

        // Prepare array that accumulate result of right-left multiplication.
        //      ex: {a,b,c,d} -> {abcd,bcd,cd,d}
        vector<int> res = nums;
        for(int i = N - 2; i >= 0; i--) {
            res[i] *= res[i + 1];
        }

        // Prepare array that accumulate result of left-right multiplication.
        //      ex: {a,b,c,d} -> {a,ab,abc,abcd}
        for(int i = 1; i < N; i++) {
            nums[i] *= nums[i - 1];
        }

        // Answer is:
        //      value of index[i] = (index[i - 1] of left-right multiplicated array) * (index[i + 1] of right-left multiplicated array)
        res[0] = res[1];
        for(int i = 1; i < N - 1; i++) {
            res[i] = nums[i - 1] * res[i + 1];
        }
        res[N - 1] = nums[N - 2];

        return res;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums, outp;
};

const int TCASE_SIZE = 2;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{{1,2,3,4}, {24,12,8,6}},
        Testing{{-1,1,0,-3,3}, {0,0,9,0,0}},
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.productExceptSelf(tcase.nums);
        if(res != tcase.outp) {
            cout << "FAIL" << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
