/**
 * Leetcode 35) https://leetcode.com/problems/search-insert-position/
 *
 * Search Insert Position
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Testing ----- */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(nums[m] < target) {
                l = m + 1;
            } else if(target < nums[m]) {
                r = m - 1;
            } else {
                return m;
            }
        }
        return target <= nums[l] ? l : l + 1;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums;
    int target, outp;
};

const int TCASE_SIZE = 5;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{{1,3,5,6}, 5, 2},
        Testing{{1,3,5,6}, 2, 1},
        Testing{{1,3,5,6}, 7, 4},
        Testing{{1,3,5,6}, 0, 0},
        Testing{{1}, 0, 0},
    };

    Solution s;

    for(auto& tcase : t) {
        int res = s.searchInsert(tcase.nums, tcase.target);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
