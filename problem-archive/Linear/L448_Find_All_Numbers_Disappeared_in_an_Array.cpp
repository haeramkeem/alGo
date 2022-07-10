/**
 * Leetcode 448) https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 *
 * Find All Numbers Disappeared in an Array
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(auto num : nums) {
            num = num > 200000 ? num % 200000 - 1 : num - 1;
            nums[num] += 200000;
        }
        for(size_t i = 0; i < nums.size(); i++) {
            if(nums[i] < 200000) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums;
    vector<int> outp;
    static void print(const vector<int>& vec) {
        cout << "{ ";
        for(const auto& el : vec) {
            cout << el << ' ';
        }
        cout << "}\n";
    }
};

const int TCASE_SIZE = 2;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{{4,3,2,7,8,2,3,1}, {5,6}},
        Testing{{1,1}, {2}},
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.findDisappearedNumbers(tcase.nums);
        if(res != tcase.outp) {
            cout << "FAIL:\nwant: ";
            Testing::print(tcase.outp);
            cout << "got: ";
            Testing::print(res);
            return 1;
        }
    }

    cout << "ok" << endl;

    return 0;
}
