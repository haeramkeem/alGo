/**
 * Leetcode 75) https://leetcode.com/problems/sort-colors/
 *
 * Sort Colors
 *
 * ref: Counting sort
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
 		array<int, 3> arr = {0, 0, 0};
		for(const auto& num : nums) { arr[num]++; }
		auto it = nums.begin();
		for(int i = 0; i < arr[0]; i++) { *it = 0; it++; }
		for(int i = 0; i < arr[1]; i++) { *it = 1; it++; }
		for(int i = 0; i < arr[2]; i++) { *it = 2; it++; }
    }
};

/* ----- Solution ----- */
struct Testing {
	vector<int> vecIn;
	vector<int> vecOut;
};

const int TCASE_SIZE = 4;

int main() {
	Testing t[TCASE_SIZE] = {
		Testing{{2, 0, 2, 1, 1, 0}, {0, 0, 1, 1, 2, 2}},
		Testing{{2, 0, 1}, {0, 1, 2}},
		Testing{{0}, {0}},
		Testing{{1}, {1}},
	};

	Solution s;

	for(auto& tcase : t) {
		s.sortColors(tcase.vecIn);
		if(tcase.vecIn != tcase.vecOut) {
			cout << "FAIL" << endl;
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
