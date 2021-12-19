/**
 * Leetcode 394) https://leetcode.com/problems/decode-string/
 *
 * Decode String
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    string decodeString(string s) {
        stack<string> chStk, nStk;
        chStk.push("");
        nStk.push("");
        for(const char& ch : s) {
            if('a' <= ch && ch <= 'z') {
                string t = chStk.top();
                chStk.pop();
                chStk.push(t + ch);
            } else if(ch == '[') {
                chStk.push("");
                nStk.push("");
            } else if(ch == ']') {
                string t = chStk.top();
                chStk.pop();

                nStk.pop();
                int rep = stoi(nStk.top());
                nStk.pop();
                nStk.push("");

                string base = chStk.top();
                chStk.pop();

                for(int i = 0; i < rep; i++) {
                    base += t;
                }

                chStk.push(base);
            } else {
                string t = nStk.top();
                nStk.pop();
                nStk.push(t + ch);
            }
        }

        return chStk.top();
    }
};

/* ----- Testing ----- */
struct Testing {
    string s, o;
    Testing(): Testing("", "") {}
    Testing(string ss, string oo): s(ss), o(oo) {}
    static const int SIZE = 5;
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing("3[a]2[bc]", "aaabcbc"),
        Testing("3[a2[c]]", "accaccacc"),
        Testing("2[abc]3[cd]ef", "abcabccdcdcdef"),
        Testing("abc3[cd]xyz", "abccdcdcdxyz"),
        Testing("3[z]2[2[y]pq4[2[jk]e1[f]]]ef", "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef"),
    };

    for(auto& tcase : t) {
        Solution s;
        auto res = s.decodeString(tcase.s);
        if(res != tcase.o) {
            cout << "FAIL want " << tcase.o << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok\n";
    return 0;
}
