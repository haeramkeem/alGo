/**
 * Leetcode 878)
 *
 * Nth Magical Number
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Soultion ----- */
#define MOD 1000000007
class Solution {
    int euclid(const int& nmax, const int& nmin) {
        if(nmax % nmin == 0) { return nmin; }
        return euclid(nmin, nmax % nmin);
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        if(a == b) {
            return static_cast<uint64_t>(a) * static_cast<uint64_t>(n) % MOD;
        }
        //  The key point of this problem is finding rules for Sequence of Magical Number.
        //      for example, when aclculating Sequence of Magical Number for 4 and 6,
        //          Sequence of Magical Number == { 4, 6, 8, 12, 16, 18, 20, 24, 28, 30, 32, 36 ... }
        //      When you look at that example above carefully, you can find 
        //          { 4 + LCM * k, 6 + LCM * k, 8 + LCM * k, 12 + LCM * k} is repeating over and over again
        //      So all you have to do is making that frame and finding k and index of it.
        uint64_t lcm = a * b / euclid(max(a, b), min(a, b));
        vector<uint64_t> frame = { lcm };
        for(int i = 1; i < lcm / a; i++) { frame.push_back(a * i); }
        for(int i = 1; i < lcm / b; i++) { frame.push_back(b * i); }
        sort(frame.begin(), frame.end());
        n--;
        int mul = n / frame.size(), idx = n % frame.size();
        return (frame[idx] + lcm * mul) % MOD;
    }
};

/* ----- Testing ----- */
struct Testing {
    int n, a, b, outp;
    Testing(int nn, int aa, int bb, int oo): n(nn), a(aa), b(bb), outp(oo) {}
    static const int SIZE = 4;
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing(1, 2, 3, 2),
        Testing(4, 2, 3, 6),
        Testing(5, 2, 4, 10),
        Testing(3, 6, 4, 8),
    };

    for(auto& tcase : t) {
        Solution s;
        auto res = s.nthMagicalNumber(tcase.n, tcase.a, tcase.b);
        if(res != tcase.outp) {
            cout << "FAIL want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
