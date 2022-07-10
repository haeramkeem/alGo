/**
 * BOJ 2110) https://www.acmicpc.net/problem/2110
 *
 * Installing router
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int main() {
	toofast;

	int n, c;
	cin >> n >> c;

	vector<int> x(n);
	for(int i = 0; i < n; i++) { cin >> x[i]; }
	
	sort(x.begin(), x.end());
	int nMin = 1, nMax = (x.back() - x.front()) * 2 / c, nRes = 1;

	while(nMin <= nMax) {
		int before = x[0], dis = nMax, nMid = (nMin + nMax) / 2, cnt = c - 1;
		for(size_t i = 1; i < x.size(); i++) {
			if(x[i] - before >= nMid) {
				cnt--;
				before = x[i];
			}
		}
		if(cnt > 0) {
			nMax = nMid - 1;
		} else {
			nMin = nMid + 1;
			nRes = max(nRes, nMid);
		}
	}

	cout << nRes << endl;
	return 0;
}
