/**
 * CNU week6
 * 
 * Exclusive trade route
 * 
 * BFS
 */

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int nCities, nRoads;

bool fnVisit(const vector<vector<int>>& vecMap) {
	// 방문체크를 위한 배열 선언
	vector<bool> visited(nCities);
	// 첫번째 노드를 방문함드로 명시
	visited[0] = true;
	// 큐를 생성하고 첫번째 노드를 삽입함
	queue<int> q;
	q.push(0);
	// 큐가 비어있지 않을때까지 반복
	while(!q.empty()) {
		// 큐의 헤드를 받아오고 pop함
		int h = q.front();
		q.pop();
		// 큐와 인접한 노드들을 순회함
		for(const auto& n : vecMap[h]) {
			// 만약 방문하지 않은 인접 노드가 있을때
			if(!visited[n]) {
				// 방문함으로 변경하고
				visited[n] = true;
				// 해당 노드를 큐에 넣어줌
				q.push(n);
			}
		}
	}
	// 모든 노드를 방문하였는지 체크하여
	//     방문하지 않은 노드가 있으면 단절되었다는 뜻이므로 
	//     false를 반환하고 종료
	for(const auto& el : visited) {
		if(!el) {
			return false;
		}
	}
	// 모든 노드를 방문하였으면 true를 반환하고 종료
	return true;
}

// 도로를 이용해 노드들간의 양방향 그래프를 만들어주는 함수
vector<vector<int>> fnGetConn(const set<array<int, 2>>& vecRoads) {
	// 양방향 그래프를 저장할 배열
	vector<vector<int>> vecMap(nCities);
	// 도로들을 하나씩 순회함
	for(const auto& road : vecRoads) {
		// 양방향 그래프이므로 서로서로 연결되어있다고 명시
		vecMap[road[0]].push_back(road[1]);
		vecMap[road[1]].push_back(road[0]);
	}
	// 양방향 그래프를 반환
	return vecMap;
}

int main() {
	// 도로들에 대한 input을 입력받음
	cin >> nCities >> nRoads;
	set<array<int, 2>> vecRoads;
	for(int i = 0; i < nRoads; i++) {
		array<int, 2> road;
		cin >> road[0] >> road[1];
		sort(road.begin(), road.end());
		vecRoads.insert(road);
	}

	// 독점 무역로에 대한 집합
	set<array<int, 2>> vecRes;

	// 도로들을 하나씩 순회하며
	for(const auto& road : vecRoads) {
		// 도로 목록에 대한 복사본을 생성하고 도로 하나를 제거함
		auto deleted = vecRoads;
		deleted.erase(find(deleted.begin(), deleted.end(), road));
		// 제거된 도로 목록을 이용해 양방향 그래프를 생성
		auto delConn = fnGetConn(deleted);
		// 각 도시들을 순회하여 만약 단절된 도시가 있으면 제거한 도로를 결과에 넣어줌
		if(!fnVisit(delConn)) {
			vecRes.insert(road);
		}
	}

	// 독점 무역로 집합을 출력함
	for(const auto& road : vecRes) {
		cout << road[0] << ' ' << road[1] << endl;
	}

	return 0;
}
