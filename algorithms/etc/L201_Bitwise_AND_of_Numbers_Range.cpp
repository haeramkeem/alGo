/**
 * Leetcode 201) https://leetcode.com/problems/bitwise-and-of-numbers-range/
 * 
 * Bitwise AND of Numbers Range
 * 
 * ref: bitwise operation
 */

#include <iostream>
#include <cmath>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int nCnt = 0;
        while(left != right) { left >>= 1; right >>= 1; nCnt++; }
        return left << nCnt;
    }
};

/* ----- Testing ----- */
struct Testing {
    int nLeft;
    int nRight;
    int nOut;
};

int main() {
    Testing t[3] = {
        Testing{5, 7, 4},
        Testing{0, 0, 0},
        Testing{1, 2147483647, 0},
    };

    Solution s;
    int nRes;
    for(const auto& tcase : t) {
        nRes = s.rangeBitwiseAnd(tcase.nLeft, tcase.nRight);
        if(nRes != tcase.nOut) {
            cout << "FAIL: want " << tcase.nOut << ", got " << nRes << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}