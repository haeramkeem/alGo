/**
 * Leetcode 1446) https://leetcode.com/problems/consecutive-characters/
 *
 * Consecutive Characters
 */

#include <iostream>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int maxPower(string s) {
        int nmax = 1;
        for(auto it = s.begin(); it < s.end() - 1; it++) {
            int cnt = 1;
            for(; it < s.end() - 1 && *it == *(it + 1); it++) { cnt++; }
            nmax = max(nmax, cnt);
        }
        return nmax;
    }
};

/* ----- Testing ----- */
struct Testing {
    string s;
    int outp;
    static const int SIZE = 5;
    Testing(string ss, int o): s(ss), outp(o) {}
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing("leetcode", 2),
        Testing("abbcccddddeeeeedcba", 5),
        Testing("triplepillooooow", 5),
        Testing("hooraaaaaaaaaaay", 11),
        Testing("tourist", 1),
    };

    for(auto& tcase : t) {
        Solution s;
        auto res = s.maxPower(tcase.s);
        if(res != tcase.outp) {
            cout << "FAIL want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
