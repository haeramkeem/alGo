#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

/* ----- Domain ----- */
struct EdgeInfo {
	int u;
	int v;
	int cost;
	bool operator<(EdgeInfo e) const { return this->cost < e.cost; }
	bool operator>(EdgeInfo e) const { return this->cost > e.cost; }
};

/* ----- Solution ----- */
void prim(const vector<int>& nodes, const vector<EdgeInfo>& edges) {
	// To get an edge of lowest cost, use priority queue.
	priority_queue<EdgeInfo, vector<EdgeInfo>, greater<EdgeInfo>> pq;

	// Generate connection map of nodes.
	map<int, vector<EdgeInfo>> conn;
	map<int, bool> visited;
	for(const auto& edge : edges) {
		if(conn.count(edge.u) == 0) { conn[edge.u] = {}; }
		conn[edge.u].push_back(edge);
		visited[edge.u] = false;
		if(conn.count(edge.v) == 0) { conn[edge.v] = {}; }
		conn[edge.v].push_back(edge);
		visited[edge.v] = false;
	}

	// For storing result.
	vector<EdgeInfo> res;
	int sum = 0;

	// Set the first node to starting point. Any node is possible.
	int it = nodes.front();
	do {
		// Set current node to visited.
		visited[it] = true;

		// Push all edges connected with current node to priority queue.
		for(const auto& next : conn[it]) { pq.push(next); }

		// Search edge that is lowest cost and that of destination is not visited.
		EdgeInfo h;
		do { h = pq.top(); pq.pop(); } while(visited[h.v] && !pq.empty());

		// If destination of selected edge has not been visited,
		//     move iterator to next destination and update results.
		if(!visited[h.v]) {
			it = h.v;
			res.push_back(h);
			sum += h.cost;
		}
	} while(!pq.empty());

	// Print result
	for(const auto& edge : res) {
		cout << "from " << edge.u << " to " << edge.v << ": cost " << edge.cost << endl;
	}
	cout << sum << endl;
}

/* ----- Testing ----- */
int main() {
	vector<int> nodes = {1, 2, 3, 4, 5};
	vector<EdgeInfo> edges = {
		EdgeInfo{1, 2, 5},
		EdgeInfo{1, 3, 4},
		EdgeInfo{2, 3, 2},
		EdgeInfo{2, 4, 7},
		EdgeInfo{3, 4, 6},
		EdgeInfo{3, 5, 11},
		EdgeInfo{4, 5, 3},
		EdgeInfo{4, 6, 8},
		EdgeInfo{5, 6, 8},
	};

	prim(nodes, edges);
	return 0;
}
