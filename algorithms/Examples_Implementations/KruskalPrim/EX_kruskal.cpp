#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* ----- Domain ----- */
class RankSet {
	// This is how a set is represented.
	//     Set : {1, 2, 3} and if 1 is root,
	//     Tree : 1 - 2
	//              + 3
	//     parent : parent[1] == 1; parent[2] == 1; parent[3] == 1;
	//     rank : rank[1] == 1; rank[2] == 0; rank[3] == 0;
	unordered_map<int, int> parent;
	unordered_map<int, int> rank;
public :
	// Make all nodes into sets of size 1.
	RankSet(const vector<int>& nodes) {
		for(const auto& node : nodes) {
			parent[node] = node;
			rank[node] = 0;
		}
	}

	// Find the root of a given node.
	int find(const int& v) {
		if(parent[v] == v) { return v; }
		return find(parent[v]);
	}
	
	// Unions two sets containing the given nodes.
	void unionOp(const int& u, const int& v) {
		int uRoot = find(u), vRoot = find(v);

		// If v's root has a higher rank, set u's root as a child of v's root.
		if(rank[uRoot] < rank[vRoot]) {
			parent[uRoot] = vRoot;
		
		// If the rank of u's root is bigger or equal to the rank of v's root, set v's root as a child of u's root.
		} else {
			parent[vRoot] = uRoot;

			// Since the u's root becomes a new root,
			//     the rank of the u's root is increased when the two roots have the same rank.
			if(rank[uRoot] == rank[vRoot]) {
				rank[uRoot]++;
			}
		}
	}
};

struct EdgeInfo {
	int u;
	int v;
	int cost;
};

void kruskal(const vector<int>& nodes, vector<EdgeInfo> edges) {
	// Make all nodes to sets of size 1.
	RankSet s(nodes);

	// Sort edges by their cost.
	sort(edges.begin(), edges.end(), [](const EdgeInfo& e1, const EdgeInfo& e2) {
		return e1.cost < e2.cost;
	});

	vector<EdgeInfo> res;
	int sum = 0;

	for(const auto& edge : edges) {

		// Accept an edge when two nodes of edge are contained to the different set.
		//     this is because when two sets are equal, including that edge will makes circular path.
		if(s.find(edge.u) != s.find(edge.v)) {
			res.push_back(edge);
			sum += edge.cost;

			// Unions two set containing two nodes of a edge.
			s.unionOp(edge.u, edge.v);
		}
	}

	// Print result
	for(const auto& edge : res) {
		cout << "from " << edge.u << " to " << edge.v << ": cost " << edge.cost << endl;
	}
	cout << "Minimum cost: " << sum << endl;
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

	kruskal(nodes, edges);

	return 0;
}
