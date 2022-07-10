/**
 * Leetcode 260) https://leetcode.com/problems/single-number-iii/
 *
 * Single Number 3
 *
 * Unordered set version
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
 		if(nums.size() == 2) { return nums; }
		unordered_set<int> s;
		s.reserve(nums.size() / 2 + 1);
		for(const auto& num : nums) {
			if(s.count(num) == 0) {
				s.insert(num);
			} else {
				s.erase(num);
			}
		}
		vector<int> res(s.begin(), s.end());
		return res;
    }
};

/* ----- Testing ----- */
struct Testing {
	vector<int> nums;
	vector<int> outp;
	static void print(const vector<int>& v) {
		for(const auto& num : v) {
			cout << num << ' ';
		}
		cout << endl;
	}
};

const int TCASE_SIZE = 3;

int main() {
	Testing t[TCASE_SIZE] = {
		Testing{{1, 2, 1, 3, 2, 5}, {5, 3}},
		Testing{{-1, 0}, {-1, 0}},
		Testing{{0, 1}, {0, 1}},
	};

	Solution s;

	for(auto& tcase : t) {
		auto res = s.singleNumber(tcase.nums);
		if(res != tcase.outp) {
			cout << "FAIL\nwant: " << endl;
			Testing::print(tcase.outp);
			cout << "got: " << endl;
			Testing::print(res);
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
