/**
 * BOJ 1197) https://www.acmicpc.net/problem/1197
 *
 * MST
 *
 * Kruskal version
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

class RankSet {
	map<int, int> parent, rank;
public:
	RankSet(const int& numNodes) {
		for(int i = 1; i <= numNodes; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int findRoot(const int& target) {
		if(parent[target] == target) { return target; }
		return findRoot(parent[target]);
	}

	void unionSet(const int& u, const int& v) {
		int uRoot = findRoot(u), vRoot = findRoot(v);
		if(rank[uRoot] < rank[vRoot]) {
			parent[uRoot] = vRoot;
		} else {
			parent[vRoot] = uRoot;
			if(rank[uRoot] == rank[vRoot]) {
				rank[uRoot]++;
			}
		}
	}
};

int main() {
	toofast;
	int v, e;
	cin >> v >> e;

	vector<array<int, 3>> edges(e);
	for(int i = 0; i < e; i++) {
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
	}

	RankSet rs(v);

	sort(edges.begin(), edges.end(), [](const array<int, 3>& arr1, const array<int, 3>& arr2) {
		return arr1[2] < arr2[2];
	});

	int res = 0;
	for(const auto& edge : edges) {
		if(rs.findRoot(edge[0]) != rs.findRoot(edge[1])) {
			res += edge[2];
			rs.unionSet(edge[0], edge[1]);
		}
	}

	cout << res << endl;

	return 0;
}
