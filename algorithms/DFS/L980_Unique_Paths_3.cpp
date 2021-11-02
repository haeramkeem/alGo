/**
 * Leetcode 980) https://leetcode.com/problems/unique-paths-iii/
 *
 * Unique Paths 3
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

/* ----- Solution ----- */
class Solution {
	int walkable, cnt, rSize, cSize;
	array<int, 2> start, end;
	int dr[4] = {-1, 0, 1, 0};
	int dc[4] = {0, 1, 0, -1};
	void walk(vector<vector<int>>& grid, const array<int, 2>& cur, const int& step) {
		if(cur == end) {
			if(walkable == step - 1) {
				cnt++;
			}
		} else {
			for(int d = 0; d < 4; d++) {
				int nr = cur[0] + dr[d], nc = cur[1] + dc[d];
				if(0 <= nr && nr < rSize && 0 <= nc && nc < cSize && (grid[nr][nc] == 0 || grid[nr][nc] == 2)) {
					grid[nr][nc] = 3;
					walk(grid, {nr, nc}, step + 1);
					grid[nr][nc] = 0;
				}
			}
		}
	}
public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		walkable = 0;
		cnt = 0;
		rSize = grid.size();
		cSize = grid[0].size();
		for(int r = 0; r < rSize; r++) {
			for(int c = 0; c < cSize; c++) {
				switch(grid[r][c]) {
					case 1 : start = {r, c}; break;
					case 2 : end = {r, c}; break;
					case 0 : walkable++; break;
				}
			}
		}
		walk(grid, start, 0);
		return cnt;
	}
};

/* ----- Testing ----- */
const int TCASE_SIZE = 3;

struct Testing {
	vector<vector<int>> grid;
	int output;
};

int main() {
	Testing t[TCASE_SIZE] = {
		Testing{{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}}, 4},
		Testing{{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}}, 2},
		Testing{{{0, 1}, {2, 0}}, 0},
	};

	Solution s;

	for(auto& tcase : t) {
		int nRes = s.uniquePathsIII(tcase.grid);
		if(tcase.output != nRes) {
			cout << "FAIL: want " << tcase.output << ", got " << nRes << endl;
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
