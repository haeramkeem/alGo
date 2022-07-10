/**
 * Leetcode 540) https://leetcode.com/problems/single-element-in-a-sorted-array/
 *
 * Single Element in a Sorted Array
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l + 2 < r) {
            int m = (l + r) / 2;
            if(nums[m] == nums[m + 1]) {
                if((m - l) % 2 == 0) {
                    l = m;
                } else {
                    r = m - 1;
                }
            } else if(nums[m - 1] == nums[m]) {
                if((m - l) % 2 == 0) {
                    r = m;
                } else {
                    l = m + 1;
                }
            } else {
                return nums[m];
            }
        }
        return nums[(l + r) / 2] == nums[r] ? nums[l] : nums[r];
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums;
    int outp;
};

const int TCASE_SIZE = 2;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{{1,1,2,3,3,4,4,8,8}, 2},
        Testing{{3,3,7,7,10,11,11}, 10},
    };

    Solution s;

    for(auto& tcase : t) {
        int res = s.singleNonDuplicate(tcase.nums);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
