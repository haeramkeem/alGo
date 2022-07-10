/**
 * Leetcode 260) https://leetcode.com/problems/single-number-iii/
 *
 * Single Number 3
 *
 * XOR version
 *
 * algorithm reference: https://leetcode.com/problems/single-number-iii/discuss/1561847/C%2B%2B-EASY-INTUITIVE-SOL-oror-BIT-MANIPULATION-oror-O(N)-time-and-O(1)-Space-Complexity
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    
    // Utility function that returns MSB of a number in O(1) time (basically a mask of MSB)
    
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int bucket1{}, bucket2{};
        long long int xr{};
        
		//Calculate xor of every number so that xr will have (x^y)
        for(int i{}; i<n; ++i) 
            xr = xr ^ nums[i];
        
		// Compute rightmost set bit of xr, gives us the ith bit we need as a mask
        int mask = xr & (-xr);
        
		// Fill our buckets according to our intuition mentioned in above steps
        for(int i{}; i<n; ++i){
            
            if(mask & nums[i])
                bucket1 ^= nums[i];
            
            else
                bucket2 ^= nums[i];
        }
        
        return { bucket1, bucket2 };
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
		Testing{{1, 2, 1, 3, 2, 5}, {3, 5}},
		Testing{{-1, 0}, {-1, 0}},
		Testing{{0, 1}, {1, 0}},
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
