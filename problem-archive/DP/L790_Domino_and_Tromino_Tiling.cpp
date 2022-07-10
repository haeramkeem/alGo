/**
 * Leetcode 790) https://leetcode.com/problems/domino-and-tromino-tiling/
 *
 * Domino and Tromino Tiling
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
#define MOD 1000000007
class Solution {
    vector<int> cache;
    int numTilingsImpl(const int& n) {
        if(n < 0) { return 0; }
        if(n == 0) { return 1; }
        if(cache[n] != 0) { return cache[n]; }
        uint64_t acc = 0;
        for(int i = 0; i < n; i++) {
            acc += numTilingsImpl(i) * (n - i > 2 ? 2 : 1);
        }
        return cache[n] = acc % MOD;
    }
public:
    int numTilings(int n) {
        cache.resize(n + 1, 0);
        return numTilingsImpl(n);
    }
};

/* ----- Testing ----- */
struct Testing {
    int n, outp;
    static const int SIZE = 7;
    Testing(int nn, int oo): n(nn), outp(oo) {}
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing(1, 1),
        Testing(2, 2),
        Testing(3, 5),
        Testing(4, 11),
        Testing(5, 24),
        Testing(6, 53),
        Testing(60, 882347204),
    };

    for(auto& tcase : t) {
        Solution s;
        auto res = s.numTilings(tcase.n);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok\n";
    return 0;
}
