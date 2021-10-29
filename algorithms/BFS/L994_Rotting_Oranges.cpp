/**
 * Leetcode 994) https://leetcode.com/problems/rotting-oranges/
 *
 * Rotting Oranges
 */

#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
		queue<array<int, 3>> q;
		int nTot = 0;
		for(int nRow = 0; nRow < static_cast<int>(grid.size()); nRow++) {
			for(int nCol = 0; nCol < static_cast<int>(grid[0].size()); nCol++) {
				if(grid[nRow][nCol] == 2) {
					q.push({nRow, nCol, 0});
				} else if(grid[nRow][nCol] == 1) {
					nTot++;
				}
			}
		}
		array<int, 4> dRow = {-1, 0, 1, 0}, dCol = {0, 1, 0, -1};
		int nCnt = 0, nMin = 0;
		while(!q.empty()) {
			auto cur = q.front();
			q.pop();
			nMin = max(nMin, cur[2]);
			for(int d = 0; d < 4; d++) {
				int nRow = cur[0] + dRow[d], nCol = cur[1] + dCol[d];
				if(0 <= nRow && nRow < grid.size() && 0 <= nCol && nCol < grid[0].size() && grid[nRow][nCol] == 1) {
					q.push({nRow, nCol, cur[2] + 1});
					grid[nRow][nCol] = 2;
					nCnt++;
				}
			}
		}
		return nCnt == nTot ? nMin : -1;
    }
};

/* ----- Testing ----- */
struct Testing {
	vector<vector<int>> vecIn;
	int nOut;
};

const int TCASE_SIZE = 3;

int main() {
	Testing t[TCASE_SIZE] = {
		Testing{{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1},
		Testing{{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4},
		Testing{{{0, 2}}, 0},
	};

	Solution s;

	for(auto tcase : t) {
		auto nRes = s.orangesRotting(tcase.vecIn);
		if(nRes != tcase.nOut) {
			cout << "FAIL: want " << tcase.nOut << ", got " << nRes << endl;
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
