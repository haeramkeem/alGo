#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

// 간선의 정보를 저장하기 위한 자료구조
struct Edge {
    string first;
    string second;
    int cost;
    Edge(string f, string s, int c) { first = f; second = s; cost = c; }
    bool operator<(Edge e) const { return this->cost < e.cost; }
    bool operator>(Edge e) const { return this->cost > e.cost; }
    bool operator==(Edge e) const { return this->cost == e.cost; }
};

class RankSet {
    map<string, string> parent;
    map<string, int> rank;
    public:
    // 노드 리스트를 받아 Union set을 초기화함
    // 부모를 자기 자신으로 해 자신을 루트로 설정하고
    // 자신의 높이를 0으로 설정함
    RankSet(const vector<string>& nodes) {
        for(const auto& node : nodes) {
            parent[node] = node;
            rank[node] = 0;
        }
    }

    // 부모가 자기자신이면 루트이므로 반환하고
    // 자기 자신이 아니라면 부모에 대해 재귀적으로 호출함
    string findRoot(const string& target) {
        if(parent[target] == target) { return target; }
        return findRoot(parent[target]);
    }

    // 입력받은 두 노드의 루트를 구한 후
    // 루트를 하나로 합쳐 합집합을 수행함
    void unionSet(const string& u, const string& v) {
        string uRoot = findRoot(u), vRoot = findRoot(v);
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
    int V, E;
    cin >> V >> E;

    // 노드에 대한 정보 입력
    vector<string> nodes(V);
    for(int i = 0; i < V; i++) {
        cin >> nodes[i];
    }

    // 간선들에 대한 정보 입력
    vector<Edge> edges;
    edges.reserve(E);
    for(int i = 0; i < E; i++) {
        string u, v;
        int c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
    }

    // 간선들을 비용에 따라 오름차순으로 정렬
    sort(edges.begin(), edges.end());

    set<int> costs;
    // 비활성화시킬 간선을 하나 지정해 이외의 간선들로 최소비용을 구함
    for(int i = 0; i < E; i++) {
        RankSet rs(nodes);
        int res = 0;
        for(int j = 0; j < E; j++) {
            if(i != j) {
                auto edge = edges[j];
                if(rs.findRoot(edge.first) != rs.findRoot(edge.second)) {
                    res += edge.cost;
                    rs.unionSet(edge.first, edge.second);
                }
            }
        }
        // 구한 최소비용을 set에 넣어 중복을 제거하고 오름차순으로 정렬
        costs.insert(res);
    }

    // 구한 최소비용들 중 두번째로 적은 값을 출력함
    auto it = costs.begin();
    it++;
    cout << *it << endl;

    return 0;
}
