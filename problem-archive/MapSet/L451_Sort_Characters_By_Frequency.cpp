/**
 * Leetcode 451) https://leetcode.com/problems/sort-characters-by-frequency/
 *
 * Sort Characters By Frequency
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    string frequencySort(string s) {
		map<char, int> m;
		for(const auto& ch : s) {
			if(m.count(ch) == 0) {
				m[ch] = 0;
			}
			m[ch]++;
		}
		
		vector<pair<char, int>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {
			if(p1.second == p2.second) { return p1.first < p2.first; }
			return p1.second > p2.second;
		});

		auto it = s.begin();
		for(const auto& p : v) {
			for(int i = 0; i < p.second; i++) {
				*(it++) = p.first;
			}
		}
		return s;
    }
};

/* ----- Testing ----- */
struct Testing {
	string strIn;
	string strOut;
};

const int TCASE_SIZE = 3;

int main() {
	Testing t[TCASE_SIZE] = {
		Testing{"tree", "eert"},
		Testing{"cccaaa", "aaaccc"},
		Testing{"Aabb", "bbAa"},
	};

	Solution s;

	for(auto tcase : t) {
		auto res = s.frequencySort(tcase.strIn);
		if(tcase.strOut != res) {
			cout << "FAIL: want " << tcase.strOut << ", got " << res << endl;
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
