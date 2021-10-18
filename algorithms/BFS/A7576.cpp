/**
 * BOJ 7576) https://www.acmicpc.net/problem/7576
 * 
 * Tomato
 * 
 * ref: Grid BFS
 */

#include <iostream>
#include <queue>

using namespace std;

struct Cor {
	int nR;
	int nC;
    int nDay;
};

int main() {
    int nRowSize, nColSize, nMax = 0;
	cin >> nColSize >> nRowSize;
    vector<vector<int>> vecMap(nRowSize);
    queue<Cor> q;

	for(int i = 0; i < nRowSize; i++) {
		vector<int> vecTemp(nColSize);
		for(int j = 0; j < nColSize; j++) {
            cin >> vecTemp[j];
            if(vecTemp[j] == 1) { q.push(Cor{i, j, 0}); }
		}
        vecMap[i] = vecTemp;
	}
    

	while(!q.empty()) {
		Cor h = q.front();
		q.pop();
        nMax = h.nDay;
		if(h.nR - 1 >= 0 && vecMap[h.nR - 1][h.nC] == 0) {
			q.push(Cor{h.nR - 1, h.nC, h.nDay + 1});
            vecMap[h.nR - 1][h.nC] = 1;
		}
		if(h.nC + 1 < nColSize && vecMap[h.nR][h.nC +1] == 0) {
			q.push(Cor{h.nR, h.nC + 1, h.nDay + 1});
            vecMap[h.nR][h.nC + 1] = 1;
		}
		if(h.nR + 1 < nRowSize && vecMap[h.nR + 1][h.nC] == 0) {
			q.push(Cor{h.nR + 1, h.nC, h.nDay + 1});
            vecMap[h.nR + 1][h.nC] = 1;
		}
		if(h.nC - 1 >= 0 && vecMap[h.nR][h.nC - 1] == 0) {
			q.push(Cor{h.nR, h.nC - 1, h.nDay + 1});
            vecMap[h.nR][h.nC - 1] = 1;
		}
	}

    for(int i = 0; i < nRowSize; i++) {
		for(int j = 0; j < nColSize; j++) {
            if(vecMap[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
		}
	}

    cout << nMax << endl;

    return 0;
}