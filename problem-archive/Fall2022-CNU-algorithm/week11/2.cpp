#include <iostream>
#include <vector>
#include <array>
#include <map>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define INTMAX 2147483647

struct Edge {
    string first, second;
    int cost;
};

int main() {
    TOOFAST;

    int V, E;
    cin >> V >> E;

    string start, end;
    cin >> start >> end;

    // 바로 이전에 거쳤던 간선과 해당 노드에 가기까지의 최소비용을 저장하기 위함
    map<string, pair<Edge, int>> D;
    // 노드 정보를 입력받으며 자료구조를 초기화함
    for(int i = 0; i < V; i++) {
        string v;
        cin >> v;
        D[v] = make_pair(Edge{start, start, INTMAX}, INTMAX);
    }
    D[start].second = 0;

    // 단방향 간선의 정보를 입력받음
    vector<Edge> edges;
    edges.reserve(2 * E);
    for(int i = 0; i < E; i++) {
        string first, second;
        int cost;
        cin >> first >> second >> cost;
        edges.push_back(Edge{first, second, cost});
    }

    // 모든 노드에 대해
    for(int i = 0; i < V - 1; i++) {
        // 모든 간선을 조사하며
        for(const auto& edge : edges) {
            // 간선의 시작점까지의 최소비용이 무한대가 아니고 간선의 도착점까지의 최소비용이
            // 간선의 시작점까지의 최소비용과 간선의 비용을 합한 것보다 클때
            // 합한 값으로 최소비용을 수정함
            if(D[edge.first].second != INTMAX && D[edge.second].second > D[edge.first].second + edge.cost) {
                D[edge.second].second = D[edge.first].second + edge.cost;
                D[edge.second].first = edge;
            }
        }
    }

    // 모든 간선에 대해 한번 더 동일한 과정을 거쳤을때 변화가 생긴다면 최소비용이 음의 무한대인 경로가 존재하므로
    // 최소비용을 알 수 없음을 출력함
    for(const auto& edge : edges) {
        if(D[edge.first].second != INTMAX && D[edge.second].second > D[edge.first].second + edge.cost) {
            cout << "Negative\n";
            return 0;
        }
    }

    // 바로 이전에 방문한 노드를 추적하며 목적지까지 가는 최소비용 경로를 알아냄
    vector<Edge> path = { D[end].first };
    string it = end;
    while(it != start) {
        path.push_back(D[it].first);
        it = D[it].first.first;
    }

    // 결과를 출력함
    for(auto rit = path.rbegin(); rit < path.rend() - 1; rit++) {
        cout << rit->first << ' ' << rit->second << ' ' << (rit->cost) << '\n';
    }

    return 0;
}
