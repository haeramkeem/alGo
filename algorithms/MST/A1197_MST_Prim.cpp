/**
 * BOJ 1197) https://www.acmicpc.net/problem/1197
 *
 * MST
 *
 * Prim version
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <queue>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int main() {
	toofast;
	int v, e;
	cin >> v >> e;

	map<int, vector<array<int, 2>>> conn;
	for(int i = 0; i < e; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		if(conn.count(v) == 0) { conn[v] = {}; }
		conn[u].push_back({c, v});
		if(conn.count(u) == 0) { conn[u] = {}; }
		conn[v].push_back({c, u});
	}

	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
	pq.push({0, 1});
	vector<bool> visited(v + 1, false);
	int res = 0;
	while(true) {
		array<int, 2> h;
		do {
			h = pq.top();
			pq.pop();
		} while (visited[h[1]] && !pq.empty());
		if(!visited[h[1]]) {
			visited[h[1]] = true;
			res += h[0];
			for(const auto& connEdge : conn[h[1]]) {
				pq.push(connEdge);
			}
		} else {
			break;
		}
	}

	cout << res << '\n';
	return 0;
}
