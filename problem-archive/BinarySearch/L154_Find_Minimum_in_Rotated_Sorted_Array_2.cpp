/**
 * Leetcode 154) https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * 
 * Find Minimum in Rotated Sorted Array II
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int findMin(vector<int>& nums) {
		if(nums.size() == 1) { return nums[0]; }
		if(nums.front() < nums.back()) { return nums[0]; }
		int l = 0, r = nums.size() - 1;
		while(l + 1 != r) {
			if(nums[l] > nums[(l + r) / 2] || nums[(l + r) / 2] < nums[r]) {
				r = (l + r) / 2;
			} else if(nums[(l + r) / 2] > nums[r] || nums[l] < nums[(l + r) / 2]) {
				l = (l + r) / 2;
			} else {
				for(int i = l; i < r; i++) {
					if(nums[i] > nums[i + 1]) {
						return nums[i + 1];
					}
				}
                break;
			}
		}
		return nums[r];
    }
};

/* ----- Testing ----- */
struct  Testing {
	vector<int> vecIn;
	int nOut;
};

const int TCASE_SIZE = 4;

int main() {
	Testing t[TCASE_SIZE] = {
		Testing{{1, 3, 5}, 1},
		Testing{{2, 2, 2, 0, 1}, 0},
        Testing{{2, 3, 2, 2, 2}, 2},
        Testing{{3, 3, 1, 3}, 1},
	};

	Solution s;

	for(auto& tcase : t) {
		int nRes = s.findMin(tcase.vecIn);
		if(nRes != tcase.nOut) {
			cout << "FAIL : want " << tcase.nOut << ", got " << nRes << endl;
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
