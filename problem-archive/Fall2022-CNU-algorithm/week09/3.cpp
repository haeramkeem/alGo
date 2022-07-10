#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <queue>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int main() {
	toofast;
	int V, E;
	cin >> V >> E;

    // 건설비용들을 입력받고 최소비용을 갖는 노드를 저장
    vector<int> buildCosts(V + 1, 2147483647);
    int minBuildCost = 0;
    for(int i = 1; i <= V; i++) {
        cin >> buildCosts[i];
        if(buildCosts[i] < buildCosts[minBuildCost]) {
            minBuildCost = i;
        }
    }

    // 간선들을 입력받아 양방향 연결관계를 연결비용과 함께 저장
	map<int, vector<array<int, 2>>> conn;
	for(int i = 0; i < E; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		if(conn.count(v) == 0) { conn[v] = {}; }
		conn[u].push_back({c, v});
		if(conn.count(u) == 0) { conn[u] = {}; }
		conn[v].push_back({c, u});
	}

	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    // 우선순위큐에 최소건설비용을 갖는 노드를 넣어 해당 노드에서부터 시작하도록 함
	pq.push({buildCosts[minBuildCost], minBuildCost});
	vector<bool> visited(V + 1, false);
	int res = 0;
	while(true) {
        // 최소 건설 혹은 연결 비용을 갖는 노드를 선택함
		array<int, 2> h;
		do {
			h = pq.top();
			pq.pop();
		} while (visited[h[1]] && !pq.empty());
		if(!visited[h[1]]) {
			visited[h[1]] = true;
            // 해당 노드의 건설 혹은 연결 비용을 결과값에 더함
			res += h[0];
            // 해당 노드와 연결할 수 있는 간선들을 우선순위 큐에 추가함
			for(const auto& connEdge : conn[h[1]]) {
				pq.push(connEdge);
			}
            // 방문하지 않은 모든 노드의 건설비용을 우선순위큐에 추가함
            for(int i = 1; i <= V; i++) {
                if(!visited[i]) {
                    pq.push({buildCosts[i], i});
                }
            }
		} else {
			break;
		}
	}

	cout << res << '\n';
	return 0;
}
