/**
 * Leetcode 442
 * 
 * Find All Duplicates in an Array
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<bool> vecAppearance(nums.size(), false);
        vector<int> vecOut;
        for(const auto& num : nums) {
            if(vecAppearance[num - 1]) {
                vecOut.push_back(num);
            } else {
                vecAppearance[num - 1] = true;
            }
        }
        return vecOut;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> vecInput;
    vector<int> vecOutput;
};

int main() {
    Testing t[3] = {
        Testing{
            {4,3,2,7,8,2,3,1},
            {2,3},
        },
        Testing{
            {1,1,2},
            {1},
        },
        Testing{
            {1},
            {},
        }
    };

    Solution s;

    for(const auto& tcase : t) {
        auto input = tcase.vecInput;
        if(tcase.vecOutput != s.findDuplicates(input)) {
            cout << "FAIL" << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}