#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
	// 표준입출력
	int n, m;
	cin >> n >> m;

	map<string, set<string>> conn;
	map<string, bool> visited;

	string city;
	for(int i = 0; i < n; i++) {
		cin >> city;
		set<string> conned;
		conn[city] = conned;
		visited[city] = false;
	}

	// 경로 입력과 동시에 도시들 간 연결관계 선언
	for(int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		// 경로 양쪽의 도시에 모두 연결되었음을 명시
		conn[a].insert(b);
		conn[b].insert(a);
	}

	// 너비 우선 탐색으로 연결된 모든 도시에 방문
	queue<string> q;
	// 모든 도시가 연결되었다는 가정 하에 어떤 도시에서 출발하여도
	//     다른 모든 도시에 도달할 수 있어야 하므로 마지막으로 입력받은 도시에서 출발
	q.push(city);
	visited[city] = true;
	while(!q.empty()) {
		// 큐의 head에 있는 도시를 꺼낸 후
		auto h = q.front();
		q.pop();
		for(const auto& next : conn[h]) {
			if(!visited[next]) {
				// 연결되어있는 도시 중 방문하지 않은 도시를 방문
				visited[next] = true;
				q.push(next);
			}
		}
	}

	// 방문 상태를 보며 방문하지 않은 도시가 있을때 False를 출력하고 종료
	for(auto it = visited.begin(); it != visited.end(); it++) {
		if(!it->second) {
			cout << "False" << endl;
			return 0;
		}
	}
	// 모든 도시에 방문하였으면 True를 출력
	cout << "True" << endl;

	return 0;
}
