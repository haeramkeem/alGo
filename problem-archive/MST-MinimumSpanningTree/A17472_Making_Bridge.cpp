/**
 * BOJ 17472) https://www.acmicpc.net/problem/17472
 *
 * Making Bridge 2
 *
 * SAMSUNG
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int n, m;
int res = 0;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

bool isOnGrid(const array<int, 2>& cur) {
	return (0 <= cur[0] && cur[0] < n && 0 <= cur[1] && cur[1] < m);
}

void makeBridge(vector<vector<int>>& grid, const array<int, 2>& cur, const int& d) {
	array<int, 2> it = cur;
	int dis = -1;
	do {
		it[0] += dr[d];
		it[1] += dc[d];
		dis++;
	} while(isOnGrid(it) && grid[it[0]][it[1]] == 0);
	if(isOnGrid(it) && grid[it[0]][it[1]] == 1 && dis > 1) {
		pq.push({dis, it[0], it[1]});
	}
}

void travel(vector<vector<int>>& grid, const array<int, 2>& start) {
	queue<array<int, 2>> q;
	q.push(start);
	grid[start[0]][start[1]] = 2;
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();
		for(int d = 0; d < 4; d++) {
			int nr = dr[d] + cur[0], nc = dc[d] + cur[1];
			if(isOnGrid({nr, nc})) {
				switch(grid[nr][nc]) {
					case 0 : makeBridge(grid, cur, d); break;
					case 1 : q.push({nr, nc}); grid[nr][nc] = 2; break;
				}
			}
		}
	}
	while(!pq.empty()) {
		auto next = pq.top();
		pq.pop();
		if(grid[next[1]][next[2]] == 1) {
			res += next[0];
			return travel(grid, {next[1], next[2]});
		}
	}
}

int main() {
	cin >> n >> m;

	vector<vector<int>> grid(n);
	for(int r = 0; r < n; r++) {
		vector<int> row(m);
		for(int c = 0; c < m; c++) {
			cin >> row[c];
		}
		grid[r] = row;
	}

	bool isTraveled = false;
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			if(grid[r][c] == 1) {
				if(isTraveled) {
					cout << -1 << '\n';
					return 0;
				} else {
					travel(grid, {r, c});
					isTraveled = true;
				}
			}
		}
	}

	cout << res << '\n';
	return 0;
}
