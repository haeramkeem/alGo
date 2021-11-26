/**
 * Leetcode 53) https://leetcode.com/problems/maximum-subarray/
 *
 * Maximum Subarray (Modified to return subarray)
 *
 * ref: Kadane's algorithm
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        // sum: variable for accumulating numbers
        // nmax: value for sum of maxSubArray
        int sum = 0, nmax = INT_MIN;

        // sub: storing accumulated numbers
        // res: maxSubArray
        // bak: if all values of given array are negative
        //      { maximum-value } is the answer
        vector<int> sub, res, bak = { INT_MIN };

        for(const auto& num : nums) {
            sum += num;

            // Consider that maxSubArray always starts with positive number.
            //      So when after accumulating value of the sum becomes negative, 
            //      We don't need to accumulate previous values.
            //      Thus, if the value of sum becomes negative, clear the subArray and the value of sum.
            if(sum < 0) {
                sum = 0;
                sub.clear();

            } else if(sum > 0) {
                // When accumulated value is positive, current number can be the element of maxSubArray.
                //      So pushes it in the subArray.
                sub.push_back(num);

                // And if accumulated value is bigger than maximum value,
                //      update the maxSubArray and maximum value.
                if(nmax < sum) {
                    res = sub;
                    nmax = sum;
                }
            }

            // This is for backup array.
            bak[0] = max(bak[0], num);
        }
        
        // When result array is empty, that means all the values in given array is negative.
        //      So returns backup array instead of result array.
        return res.size() == 0 ? bak : res;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums, outp;
};

const int TCASE_SIZE = 4;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{{-2,1,-3,4,-1,2,1,-5,4}, {4,-1,2,1}},
        Testing{{1}, {1}},
        Testing{{5,4,-1,7,8}, {5,4,-1,7,8}},
        Testing{{-2,-1}, {-1}},
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.maxSubArray(tcase.nums);
        if(res != tcase.outp) {
            cout << "FAIL";
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
