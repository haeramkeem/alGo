/**
 * BOJ 1753) https://www.acmicpc.net/problem/1753
 *
 * Shortest Path
 */

#include <functional>
#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define INTMAX 2147483647
#define COST 0
#define NODE 1

int main() {
    TOOFAST;

    int V, E;
    cin >> V >> E;

    int start;
    cin >> start;

    // conn[from][to] == cost
    vector<vector<array<int, 2>>> conn(V + 1);
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // Beware that Graph is not always biderectional
        conn[u].push_back({w, v});
    }

    // selected[target] == isSelectedNode
    vector<bool> selected(V + 1, false);

    // D[target] == distanceFromStart
    vector<int> D(V + 1, INTMAX);
    D[start] = 0;

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    // Select start node with zero cost
    pq.push({0, start});

    while(!pq.empty()) {

        // Select nearest node
        //      The key point of Dijkstra algorithm is that
        //      It ALWAYS selects the closest node against the starting node, 
        //      NOT the most recently selected node
        //      among the every nodes connected to selected nodes.
        auto h = pq.top();
        pq.pop();
        selected[h[NODE]] = true;

        for(const auto& next : conn[h[NODE]]) {

            // If next node is selected one, skip it
            if(selected[next[NODE]]) {
                continue;
            }

            // Update distance if the path that crosses current node is much shorter than older one.
            //      D[next[NODE]] == distance between start and next to current node
            //      D[h[NODE]] == distance between start and current node
            //      next[COST] == cost to move next node
            if(D[next[NODE]] > D[h[NODE]] + next[COST]) {
                D[next[NODE]] = D[h[NODE]] + next[COST];

                // Pushed to priority queue when distance is updated.
                //      It's because the fact that node is updated means that (by far) crossing current node is the shortest path to
                //      reach the next node, so this should be included to priority queue.
                pq.push({D[next[NODE]], next[NODE]});
            }
        }
    }

    // STDOUT
    for(int i = 1; i <= V; i++) {
        if(D[i] == INTMAX) {
            cout << "INF\n";
        } else {
            cout << D[i] << '\n';
        }
    }
    
    return 0;
}
