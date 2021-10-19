/**
 * P1829) https://programmers.co.kr/learn/courses/30/lessons/1829
 * 
 * Kakao Friends
 * 
 * BFS
 */

#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

int dR[4] = {-1, 0, 1, 0};
int dC[4] = {0, 1, 0, -1};

int fnVisit(vector<vector<int>>& picture, const int& nR, const int& nC) {
	queue<array<int, 2>> q;
	q.push({nR, nC});
	int nColor = picture[nR][nC];
	picture[nR][nC] = 0;
	int nCnt = 1;
	while(!q.empty()) {
		auto h = q.front();
		q.pop();
		for(int d = 0; d < 4; d++) {
			int nNR = h[0] + dR[d];
			int nNC = h[1] + dC[d];
			if(0 <= nNR && nNR < picture.size() && 0 <= nNC && nNC < picture[0].size() && picture[nNR][nNC] == nColor) {
				q.push({nNR, nNC});
				picture[nNR][nNC] = 0;
				nCnt++;
			}
		}
	}
	return nCnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> vecRes;
	for(int nR = 0; nR < m; nR++) {
		for(int nC = 0; nC < n; nC++) {
			if(picture[nR][nC] != 0) {
				vecRes.push_back(fnVisit(picture, nR, nC));
			}
		}
	}
	int nMax = -1;
	for(const auto& el : vecRes) {
		nMax = el > nMax ? el : nMax;
	}
	return {static_cast<int>(vecRes.size()), nMax};
}

int main() {
	vector<int> res = {4, 5};
	if(res != solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}})) {
		cout << "FAIL" << endl;
		return 1;
	}
	cout << "ok" << endl;
	return 0;
}