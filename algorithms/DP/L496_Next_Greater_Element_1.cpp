/**
 * L496) https://leetcode.com/problems/next-greater-element-i/
 * 
 * Next Greater Element 1
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int vtoi[10001];
		vector<int> vecRes;
		vecRes.reserve(nums1.size());
		for(int i = 0; i < nums2.size(); i++) {
			vtoi[nums2[i]] = i;
		}
		for(const auto& num : nums1) {
			int i;
			for(i = vtoi[num]; i < nums2.size(); i++) {
				if(nums2[i] > num) {
					vecRes.push_back(nums2[i]);
					break;
				}
			}
			if(i == nums2.size()) {
				vecRes.push_back(-1);
			}
		}
		return vecRes;
    }
};

struct Testing {
	vector<int> vecNums1;
	vector<int> vecNums2;
	vector<int> vecOut;
};

int main() {
	Testing t[2] = {
		Testing{{4, 1, 2}, {1, 3, 4, 2}, {-1, 3, -1}},
		Testing{{2, 4}, {1, 2, 3, 4}, {3, -1}},
	};

	Solution s;

	for(const auto& tcase : t) {
		auto vecNums1 = tcase.vecNums1;
		auto vecNums2 = tcase.vecNums2;
		if(tcase.vecOut != s.nextGreaterElement(vecNums1, vecNums2)) {
			cout << "FAIL" << endl;
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
