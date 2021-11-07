/**
 * Leetcode 43) https://leetcode.com/problems/multiply-strings/
 *
 * Multiply Strings
 */

#include <iostream>
#include <algorithm>

using namespace std;

/* ----- Solution ----- */
class Solution {
    string sum(const string& dst, const string& src) {
        string acc = "";
        acc.reserve(dst.size() + src.size() + 1);
        auto dit = dst.rbegin();
        int overflow = 0;
        for(auto sit = src.rbegin(); sit < src.rend(); sit++) {
            int t = (*dit - 48) + (*sit - 48) + overflow;
            acc += t % 10 + 48;
            overflow = t / 10;
            dit++;
        }
        for(; dit < dst.rend(); dit++) {
            int t = (*dit - 48) + overflow;
            acc += t % 10 + 48;
            overflow = t / 10;
        }
        if(overflow != 0) {
            acc += overflow + 48;
        }
        reverse(acc.begin(), acc.end());
        return acc;
    }
    string multiplyWithChar(const string& num, const char& ch, const int& pad) {
        string acc = "";
        acc.reserve(num.size() + pad + 1);
        int overflow = 0;
        for(auto rit = num.rbegin(); rit < num.rend(); rit++) {
            int t = (*rit - 48) * (ch - 48) + overflow;
            acc += t % 10 + 48;
            overflow = t / 10;
        }
        if(overflow != 0) {
            acc += overflow + 48;
        }
        reverse(acc.begin(), acc.end());
        for(int i = 0; i < pad; i++) {
            acc += '0';
        }
        return acc;
    }
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") { return "0"; }
        int N = num2.size();
        auto res = multiplyWithChar(num1, num2[0], N - 1);
        for(size_t i = 1; i < num2.size(); i++) {
            res = sum(res, multiplyWithChar(num1, num2[i], N - i - 1));
        }
        return res;
    }
};

/* ----- Testing ----- */
struct Testing {
    string num1;
    string num2;
    string outp;
};

const int TCASE_SIZE = 5;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{"2", "3", "6"},
        Testing{"123", "456", "56088"},
        Testing{"9133", "0", "0"},
        Testing{"0", "52", "0"},
        Testing{"140", "721", "100940"},
    };

    Solution s;

    for(const auto& tcase : t) {
        auto res = s.multiply(tcase.num1, tcase.num2);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
