/**
 * Leetcode 15) https://leetcode.com/problems/3sum/
 *
 * 3Sum
 */

#include <iostream>
#include <vector>
#include <set>

/* ----- Solution ----- */
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		if(nums.size() < 3) { return {}; }
		vector<vector<int>> vecRes;
        sort(nums.begin(), nums.end());
		for(auto l = nums.begin(); l < nums.end() - 1; l++) {
			if(l > nums.begin() && *l == *(l - 1)) { continue; }
			auto m = l + 1;
			auto r = nums.end() - 1;
			while(m < r) {
				if(*m + *r + *l < 0) {
					m++;
				} else if(*m + *r + *l > 0) {
					r--;
				} else {
					vecRes.push_back({*l, *m, *r});
					while(m < r && *m == *(m + 1)) { m++; }
					while(m < r && *r == *(r - 1)) { r--; }
					m++; r--;
				}
			}
		}
		return vecRes;
    }
};

/* ----- Testing ----- */
struct Testing {
	vector<int> vecIn;
	vector<vector<int>> vecOut;
};

const int TCASE_SIZE = 3;

void print(const vector<vector<int>>& vec) {
	cout << "{";
	for(const auto& el : vec) {
		cout << "{";
		for(const auto& n : el) {
			cout << n << ", ";
		}
		cout << "}, ";
	}
	cout << "}" << endl;
}

int main() {
	Testing t[TCASE_SIZE] = {
		{{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
		{{}, {}},
		{{0}, {}},
	};
	
	Solution s;
	for(auto& tcase : t) {
		auto vecRes = s.threeSum(tcase.vecIn);
		if(vecRes != tcase.vecOut) {
			cout << "FAIL\nwant: ";
			print(tcase.vecOut);
			cout << "got: ";
			print(vecRes);
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
