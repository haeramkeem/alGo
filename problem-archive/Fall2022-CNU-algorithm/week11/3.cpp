#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define INTMAX 2147483647

struct Edge{
    string src, dst;
    int cost;
};

int main() {
    TOOFAST;

    int V, E, L;
    cin >> V >> E >> L;

    vector<string> nodes(V);
    for(int i = 0; i < V; i++) {
        cin >> nodes[i];
    }

    // 한 노드에서 다른 노드로 가는 비용을 초기화함
    map<string, map<string, int>> D;
    for(const auto& s : nodes) {
        for(const auto& d : nodes) {
            if(s == d) {
                D[s][d] = 0;
            } else {
                D[s][d] = INTMAX;
            }
        }
    }

    // 간선의 정보를 입력받아 양방향 연결관계를 맺어줌
    for(int i = 0; i < E; i++) {
        string src, dst;
        int cost;
        cin >> src >> dst >> cost;
        D[src][dst] = cost;
        D[dst][src] = cost;
    }

    for(const auto& k : nodes) {
        for(const auto& i : nodes) {
            for(const auto& j : nodes) {
                // 노드 i에서 j로 가는 비용이 노드 k를 거쳐 가는 것이 더 비용이 적다면 최소비용을 수정함
                if((D[i][k] != INTMAX) && (D[k][j] != INTMAX)) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    string resNode = "";
    int resNum = -1;
    for(const auto& v : nodes) {
        int cnt = 0;
        // 각 노드에 대해 연결된 노드들과의 비용이 주어진 한계보다 작은 노드들의 갯수를 셈
        for(const auto& n : nodes) {
            if(D[v][n] <= L) {
                cnt++;
            }
        }
        // 노드 갯수의 최대값을 수정함
        if(cnt > resNum) {
            resNum = cnt;
            resNode = v;
        }
    }

    // 출력
    cout << resNode << ' ' << resNum << '\n';

    return 0;
}
