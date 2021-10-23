/**
 * Leetcode 153) https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * 
 * Find Minimum in Rotated Sorted Array
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int findMin(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		if(nums[l] < nums[r]) {
			return nums[l];
		}
		while(l < r) {
			if(nums[l] < nums[(l + r) / 2]) {
				l = (l + r) / 2;
			} else {
				r = (l + r) / 2;
			}
		}
		return nums[l + 1];
    }
};

/* ----- Testing ----- */
struct  Testing {
	vector<int> vecIn;
	int nOut;
};

const int TCASE_SIZE = 3;

int main() {
	Testing t[TCASE_SIZE] = {
		Testing{{3, 4, 5, 1, 2}, 1},
		Testing{{4, 5, 6, 7, 0, 1, 2}, 0},
		Testing{{11, 13, 15, 17}, 11},
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
