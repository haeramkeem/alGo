/**
 * Leetcode 416)
 *
 * Partition Equal Subset Sum
 *
 * ref: https://leetcode.com/problems/partition-equal-subset-sum/discuss/1624365/C%2B%2B-EASY-TO-SOLVE-ororBeginner-Friendly-Detailed-Explanation-with-a-dry-run
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size();

        int tot = 0;
        for(const auto& num : nums) { tot += num; }
        if(tot % 2 == 1) { return false; }
        tot /= 2;

        vector<bool> cache(tot + 1, false);
        cache[0] = true;
        for(const auto& num : nums) {
            for(int i = tot; i >= num; i--) {
                cache[i] = cache[i] || cache[i - num];
            }
        }

        return cache[tot];
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums;
    bool outp;
    static const int SIZE = 2;
    Testing(vector<int> n, bool o): nums(n), outp(o) {}
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({1,5,11,5}, true),
        Testing({1,2,3,5}, false),
    };

    for(auto& tcase : t) {
        Solution s;
        auto res = s.canPartition(tcase.nums);
        if(res != tcase.outp) {
            cout << "FAIL: want " << boolalpha << tcase.outp << " got " << boolalpha << res << endl;
            return 1;
        }
    }

    cout << "ok\n";
    return 0;
}
