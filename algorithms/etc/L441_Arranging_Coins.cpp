/**
 * Leetcode 441) https://leetcode.com/problems/arranging-coins/
 *
 * Arranging Coins
 *
 * ref: cmath/sqrt
 */

#include <iostream>
#include <cmath>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int arrangeCoins(int n) {
		return static_cast<int>(sqrt(2 * static_cast<double>(n) + 0.25) - 0.5);
    }
};

/* ----- Testing ----- */
struct Testing {
	int n;
	int nOut;
};

const int TCASE_SIZE = 2;

int main() {
	Testing t[TCASE_SIZE] = {
		Testing{5, 2},
		Testing{8, 3},
	};

	Solution s;

	for(const auto& tcase : t) {
		int nRes = s.arrangeCoins(tcase.n);
		if(nRes != tcase.nOut) {
			cout << "FAIL: want " << tcase.nOut << " got " << nRes << endl;
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
