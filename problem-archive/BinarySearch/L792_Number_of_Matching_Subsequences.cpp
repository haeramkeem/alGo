#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // Make a map which is:
        // map[lowerCaseCharIdx] == []idxsAppearedInS
        vector<vector<int>> charMap(26);

        for (int i = 0; i < s.size(); i++) {
            charMap[s[i] - 'a'].push_back(i);
        }

        // Instead of counting up the substrings,
        // count down the non-substrings
        int output = words.size();

        for (auto& word : words) {
            // A `last` index of the `s` string represents
            // a last index which is guaranteed to be appeared in the `word`
            int last = -1;

            for (auto& ch : word) {
                // Using '&' allows u to optimize the memory usage
                auto& idxs = charMap[ch - 'a'];

                // As idxs vector is sorted,
                // u can use upper_bound func to get iterator
                // that points the one bigger than the 'last' index
                // @see https://chanhuiseok.github.io/posts/algo-55/
                // for more information about `upper_bound` and `lower_bound` func
                auto next = upper_bound(idxs.begin(), idxs.end(), last);

                // Can't find a word's char in s
                // Current word is non-substring -> get rid of 'em
                if (next == idxs.end()) {
                    output--;
                    break;

                // Find a char which appears after the 'last' index
                // Update the `last` index with an index of found char's index
                } else {
                    last = *next;
                }
            }
        }

        return output;
    }
};

struct Testing {
    string s;
    vector<string> words;
    int output;
    static const int TSIZE = 2;
};

int main() {
    Testing t[Testing::TSIZE] = {
    };

    Solution s;
    for (auto& tcase : t) {
        auto output = s.numMatchingSubseq(tcase.s, tcase.words);
        if (output != tcase.output) {
            cout << "FAIL" << endl;
            cout << "Want: " << tcase.output << endl;
            cout << "Got: " << output << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
