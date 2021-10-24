/**
 * BOJ 1764) https://www.acmicpc.net/problem/1764
 *
 * Neither Heard Nor Seen
 */

/* ----- Solution ----- */
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int main() {
	toofast;
	int n1, n2;
	cin >> n1 >> n2;
	string strTmp;
	unordered_set<string> s;
	for(int i = 0; i < n1; i++) {
		cin >> strTmp;
		s.insert(strTmp);
	}
	vector<string> vecRes;
	vecRes.reserve(max(n1, n2));
	for(int i = 0; i < n2; i++) {
		cin >> strTmp;
		if(s.count(strTmp) == 1) {
			vecRes.push_back(strTmp);
		}
	}

	sort(vecRes.begin(), vecRes.end());
	cout << vecRes.size() << '\n';
	for(const auto& name : vecRes) {
		cout << name << '\n';
	}
	return 0;
}
