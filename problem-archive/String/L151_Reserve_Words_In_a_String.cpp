/**
 * Leetcode 151) https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Reverse Words In a String
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    string reverseWords(string s) {
		stringstream ss(s);
		vector<string> v;
		string st;
		while(getline(ss, st, ' ')) {
			if(st.size() > 0) {
				v.push_back(st);
			}
		}
		s.clear();
		for(auto it = v.rbegin(); it < v.rend() - 1; it++) {
			s += *it;
			s += " ";
		}
		return s + v.front();
    }
};

/* ----- Testing ----- */
struct Testing {
	string strIn;
	string strOut;
};

const int TCASE_SIZE = 5;

int main() {
	Testing t[5] = {
		Testing{"the sky is blue", "blue is sky the"},
		Testing{"  hello world  ", "world hello"},
		Testing{"a good   example", "example good a"},
		Testing{"  Bob    Loves  Alice   ", "Alice Loves Bob"},
		Testing{"Alice does not even like bob", "bob like even not does Alice"},
	};

	Solution s;

	for(auto tcase : t) {
		auto res = s.reverseWords(tcase.strIn);
		if(res != tcase.strOut) {
			cout << "FAIL: want \"" << tcase.strOut << "\", got \"" << res << '\"' << endl;
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
