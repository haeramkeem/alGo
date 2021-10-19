/**
 * BOJ 2178) https://www.acmicpc.net/problem/2178
 * 
 * Shortest Maze
 * 
 * ref: Grid BFS
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int dR[4] = {-1, 0, 1, 0};
int dC[4] = {0, 1, 0, -1};
int nRowSize, nColSize;

struct Cor {
	int nR;
	int nC;
	int nStep;
};

int fnVisit(vector<vector<int>>& vecMap) {
	queue<Cor> q;
	q.push(Cor{0, 0, 1});
	while(!q.empty()) {
		Cor h = q.front();
		q.pop();
		if(h.nR == nRowSize - 1 && h.nC == nColSize - 1) {
			return h.nStep;
		}
		for(int i = 0; i < 4; i++) {
			int nNR = h.nR + dR[i];
			int nNC = h.nC + dC[i];
			if(0 <= nNR && nNR < nRowSize && 0 <= nNC && nNC < nColSize && vecMap[nNR][nNC] == 1) {
				vecMap[nNR][nNC] = 0;
				q.push(Cor{nNR, nNC, h.nStep + 1});
			}
		}
	}
	return 0;
}

int main() {
	toofast;
	string strLine;
	cin >> nRowSize >> nColSize;
	vector<vector<int>> vecMap(nRowSize);
	for(int nR = 0; nR < nRowSize; nR++) {
		vector<int> vecRow(nColSize);
		cin >> strLine;
		for(int nC = 0; nC < nColSize; nC++) {
			vecRow[nC] = strLine[nC] - 48;
		}
		vecMap[nR] = vecRow;
	}

	cout << fnVisit(vecMap) << endl;
	return 0;
}
