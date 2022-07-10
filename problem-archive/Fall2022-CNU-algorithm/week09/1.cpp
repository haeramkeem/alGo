#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <queue>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

// 어떤 노드와 연결된 노드와 비용을 저장
struct Node {
    string next;
    int cost;
    Node(string n, int c) { next = n; cost = c; }
    bool operator<(Node n) const { return this->cost < n.cost; }
    bool operator>(Node n) const { return this->cost > n.cost; }
    bool operator==(Node n) const { return this->cost == n.cost; }
};

int main() {
	toofast;
	int V, E;
	cin >> V >> E;

    // 노드들을 입력받음
    string vv;
	map<string, vector<Node>> conn;
    map<string, bool> visited;
    for(int i = 0; i < V; i++) {
        cin >> vv;
        conn[vv] = {};
        visited[vv] = false;
    }

    // 간선에 대한 정보를 입력받아 양방향 연결관계를 지어줌
	for(int i = 0; i < E; i++) {
        string u, v;
		int c;
		cin >> u >> v >> c;
		conn[u].push_back(Node(v, c));
		conn[v].push_back(Node(u, c));
	}

	priority_queue<Node, vector<Node>, greater<Node>> pq;
    // 임의의 노드에서부터 시작
	pq.push(Node(vv, 0));
	int res = 0;
	while(true) {
        // 방문하지 않은 노드 중 비용이 최소인 노드를 얻음
        Node h = pq.top();
		do {
			h = pq.top();
			pq.pop();
		} while (visited[h.next] && !pq.empty());
		if(!visited[h.next]) {
            // 방문하지 않은 비용이 최소인 노드의 비용을 저장하고
            // 해당 노드와 연결되어있는 노드들을 우선순위 큐에 넣어줌
			visited[h.next] = true;
			res += h.cost;
			for(const auto& connEdge : conn[h.next]) {
				pq.push(connEdge);
			}
		} else {
			break;
		}
	}

	cout << res << '\n';
	return 0;
}
