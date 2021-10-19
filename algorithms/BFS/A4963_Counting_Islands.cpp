/**
 * BOJ4963) https://www.acmicpc.net/problem/4963
 * 
 * Counting Islands
 * 
 * BFS
 */

#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

int dR[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dC[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void fnVisit(vector<vector<int>>& vecMap, const int& nR, const int& nC) {
	queue<array<int, 2>> q;
	q.push({nR, nC});
	while(!q.empty()) {
		auto h = q.front();
		q.pop();
		for(int d = 0; d < 8; d++) {
			int nNR = h[0] + dR[d];
			int nNC = h[1] + dC[d];
			if(0 <= nNR && nNR < vecMap.size() && 0 <= nNC && nNC < vecMap[0].size() && vecMap[nNR][nNC] == 1) {
				q.push({nNR, nNC});
				vecMap[nNR][nNC] = 0;
			}
		}
	}
}

int fnCountIsland(vector<vector<int>>& vecMap) {
	int nCnt = 0;
	for(int nR = 0; nR < vecMap.size(); nR++) {
		for(int nC = 0; nC < vecMap[0].size(); nC++) {
			if(vecMap[nR][nC] == 1) {
				fnVisit(vecMap, nR, nC);
				nCnt++;
			}
		}
	}
	return nCnt;
}

int main() {
	int nRowSize, nColSize;
	vector<vector<int>> vecMap;
	cin >> nColSize >> nRowSize;
	while(nRowSize != 0 || nColSize != 0) {
		vecMap.clear();
		vecMap.reserve(nRowSize);
		for(int nR = 0; nR < nRowSize; nR++) {
			vector<int> vecRow(nColSize);
			for(int nC = 0; nC < nColSize; nC++) {
				cin >> vecRow[nC];
			}
			vecMap.push_back(vecRow);
		}
		cout << fnCountIsland(vecMap) << '\n';
		cin >> nColSize >> nRowSize;
	}
	return 0;
}
