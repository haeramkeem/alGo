#include <functional>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <map>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define INTMAX 2147483647
#define COST 0
#define NODE 1

struct Info {
    string node;
    int cost;
    Info(): node(""), cost(INTMAX) {}
    Info(string n, int c): node(n), cost(c) {}
    bool operator<(Info t) const { return this->cost < t.cost; }
    bool operator>(Info t) const { return this->cost > t.cost; }
    bool operator==(Info t) const { return this->cost == t.cost; }
};

int main() {
    TOOFAST;

    int V, E;
    cin >> V >> E;

    string start, end;
    cin >> start >> end;

    // 각 노드에 대해 바로 이전에 방문한 노드와 해당 노드에 도달하기까지의 최소비용을 저장하기 위함
    map<string, Info> D;
    // 각 노드와 연결된 노드 및 비용을 저장하기 위함
    map<string, vector<Info>> conn;
    // 방문한 노드를 체크하기 위함
    map<string, bool> selected;
    // 존재하는 노드를 입력받으며 각 자료구조를 초기화함
    for(int i = 0; i < V; i++) {
        string v;
        cin >> v;
        D[v] = Info(start, INTMAX);
        conn[v] = {};
        selected[v] = false;
    }

    // 양방향 연결관계를 생성해줌
    for(int i = 0; i < E; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        conn[u].push_back(Info(v, w));
        conn[v].push_back(Info(u, w));
    }

    // 시작노드의 비용을 0으로 바꿔줌
    D[start].cost = 0;

    // 주어진 시작노드에서 출발하도록 함
    priority_queue<Info, vector<Info>, greater<Info>> pq;
    pq.push(Info(start, 0));

    while(!pq.empty()) {

        // 현재 이동비용이 제일 적은 경로를 선택
        auto h = pq.top();
        pq.pop();

        // 선택된 노드를 방문함으로 변경
        selected[h.node] = true;

        for(const auto& next : conn[h.node]) {

            // 현재 노드와 연결된 노드중 이미 방문한 노드는 무시함
            if(selected[next.node]) {
                continue;
            }

            // 시작지점에서 현재 노드와 연결된 노드까지 가는 비용이 현재 노드를 거쳐서 가는 비용보다 클 경우
            // 해당 노드의 최소비용을 현재 노드를 거칠때의 비용으로 수정하고
            // 바로 이전에 방문한 노드를 현재 노드로 지정해주며
            // 우선순위 큐에 넣어줌
            if(D[next.node].cost > D[h.node].cost + next.cost) {
                D[next.node].cost = D[h.node].cost + next.cost;
                D[next.node].node = h.node;
                pq.push(Info(next.node, D[next.node].cost));
            }
        }
    }

    // 종점노드까지의 이동경로를 알아내기 위해 바로 이전에 방문한 노드를 추적함
    vector<string> path = { end };
    string it = end;
    while(it != start) {
        path.push_back(D[it].node);
        it = D[it].node;
    }

    // 결과 출력
    for(auto rit = path.rbegin(); rit < path.rend(); rit++) {
        cout << *rit;
    }
    cout << '\n';
    cout << D[end].cost << '\n';

    return 0;
}
