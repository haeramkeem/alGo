/**
 * BOJ 1655) https://www.acmicpc.net/problem/1655
 *
 * Median Value
 */

/* ----- Solution ----- */
#include <iostream>
#include <queue>
#include <deque>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int main() {
	toofast;
	int nTot;
	cin >> nTot;
	deque<int> deqIn(nTot);
	for(int i = 0; i < nTot; i++) {
		cin >> deqIn[i];
	}
	priority_queue<int> pqLower;
	priority_queue<int, vector<int>, greater<int>> pqBigger;
	int nMid = deqIn.front();
	deqIn.pop_front();
	cout << nMid << '\n';
	for(const auto& nTmp : deqIn) {
		if(nTmp <= nMid) {
			pqLower.push(nTmp);
		} else {
			pqBigger.push(nTmp);
		}
		if(pqLower.size() == pqBigger.size() + 1) {
			pqBigger.push(nMid);
			nMid = pqLower.top();
			pqLower.pop();
		} else if(pqLower.size() + 2 == pqBigger.size()) {
			pqLower.push(nMid);
			nMid = pqBigger.top();
			pqBigger.pop();
		}
		cout << nMid << '\n';
	}
	
	return 0;
}
