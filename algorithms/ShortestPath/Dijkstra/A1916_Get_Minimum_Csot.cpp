/**
 * BOJ 1916) https://www.acmicpc.net/problem/1916
 *
 * Get Minimum Cost
 */

#include <climits>
#include <iostream>
#include <vector>
#include <queue>

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define COST 0
#define NODE 1

using namespace std;

int main() {
    TOOFAST;
    int N, E;
    cin >> N >> E;

    vector<vector<vector<int>>> conn(N + 1);
    for(int i = 0; i < E; i++) {
        int s, d, c;
        cin >> s >> d >> c;
        conn[s].push_back({c, d});
    }

    int src, dst;
    cin >> src >> dst;

    vector<int> distance(N + 1, INT_MAX);
    distance[src] = 0;

    vector<bool> visited(N + 1, false);

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        visited[curr[NODE]] = true;

        if(curr[NODE] == dst) {
            break;
        }

        for(auto& next : conn[curr[NODE]]) {
            if(!visited[next[NODE]] && distance[next[NODE]] > distance[curr[NODE]] + next[COST]) {
                distance[next[NODE]] = distance[curr[NODE]] + next[COST];
                pq.push({distance[next[NODE]], next[NODE]});
            }
        }
    }

    cout << distance[dst] << '\n';

    return 0;
}
