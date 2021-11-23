/**
 * BOJ 11657) https://www.acmicpc.net/problem/11657
 *
 * Time Machine
 *
 * Bellman Ford Algorithm
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define INTMAX 2147483647
#define SRC 0
#define DST 1
#define COST 2
#define LL long long

int main() {
    TOOFAST;

    int V, E;
    cin >> V >> E;

    vector<array<int, 3>> edges;
    edges.reserve(E);
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // One edge is saved by { src, dst, cost } format.
        edges.push_back({a, b, c});
    }

    vector<LL> D(V + 1, INTMAX);
    D[1] = 0;

    // Relax for (V - 1) times.
    //      The key point of Bellman-Ford Algorithm is Edge-Relaxing
    //      Because distance between node A and node B can be calculated by
    //      adding distance between node A and node C(arbitrary node) and cost between node C and node B.
    //      So, by applying this calculation to the all edges, We can calculate all distances of the nodes.
    //
    //      Edge-Relaxing proceeds like this:
    //      1) If distance of the src node in edge is infinite, relaxing is canceled.
    //      2) If result of adding distance of the src node in the edge and cost of the edge is smaller than
    //          distance of the dst node in edge, update distance.
    //      3) Do this for all edges.
    //
    //      Reason for doing Edge-Relaxing for (V - 1) times:
    //      Number of nodes organizing shortest path between node A and B is vary from 0 to V - 2.
    //      (It can be AB ~ A{all nodes except A and B}B)
    //      So, repeating Edge-Relaxing for (V - 1) times will find all shortest paths.
    for(int i = 0; i < V - 1; i++) {
        for(const auto& edge : edges) {
            if(D[edge[SRC]] != INTMAX && D[edge[DST]] > D[edge[SRC]] + edge[COST]) {
                D[edge[DST]] = D[edge[SRC]] + edge[COST];
            }
        }
    }

    // Check for loop
    //      Looping issue is very important for Bellman-Ford Algorithm.
    //      When grapth contains cycle structure and in every rotation cost gets constantly decrease,
    //      It has no meaning to calcuate the shortest path.
    //      So, after doing Edge-Relaxing for (V - 1) times, Doing it once again.
    //      When some costs are still updated, we can consider it as looping.
    for(const auto& edge : edges) {
        if(D[edge[SRC]] != INTMAX && D[edge[DST]] > D[edge[SRC]] + edge[COST]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    // STDOUT
    for(int i = 2; i <= V; i++) {
        cout << (D[i] == INTMAX ? -1 : D[i]) << '\n';
    }
    return 0;
}
