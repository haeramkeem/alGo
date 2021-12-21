/**
 * Leetcode 231) https://leetcode.com/problems/power-of-two/
 *
 * Power of Two
 */

#include <iostream>
#include <cmath>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) {
            return false;
        }
        return n == pow(2, floor(log2(n)));
    }
};

/* ----- Testing ----- */
struct Testing {
    int n;
    bool o;
    static const int SIZE = 3;
    Testing(): Testing(0, false) {}
    Testing(const int& nn, const bool& oo): n(nn), o(oo) {}
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing(1, true),
        Testing(16, true),
        Testing(3, false),
    };

    for(auto& tcase : t) {
        Solution s;
        auto res = s.isPowerOfTwo(tcase.n);
        if(res != tcase.o) {
            cout << "FAIL: want " << boolalpha << tcase.o << " got " << boolalpha << res << endl;
            return 1;
        }
    }

    cout << "ok\n";
    return 0;
}
