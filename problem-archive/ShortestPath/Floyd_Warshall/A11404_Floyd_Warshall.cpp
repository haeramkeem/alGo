/**
 * BOJ 11404) https://www.acmicpc.net/problem/11404
 *
 * Floyd-Warshall
 */

#include <iostream>
#include <vector>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define INTMAX 2147483647

int main() {
    TOOFAST;

    int V, E;
    cin >> V >> E;

    // D[from][to] == cost
    vector<vector<int>> D(V + 1, vector<int>(V + 1, INTMAX));
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        D[a][b] = min(D[a][b], c);
    }

    // Set distance to itself to 0
    for(int i = 1; i <= V; i++) {
        D[i][i] = 0;
    }

    // Floyd-Warshall Algorithm
    //      The key point of Floyd-Warshall Algorithm is that
    //      distance between node A and node B can be updated to
    //      sum of distance between node A - node C and distance between node C - node B (let node C be arbitrary intermediate node)
    //      if distance of direct path is bigger than detour path.
    //      It can be formulated to:
    //      D[a][b] = min(D[a][b], D[a][c] + D[c][b])
    //      Thus, by applying this formula to all possible a, b, c, We can calculate all shortest path between two nodes contained in graph.
    for(int k = 1; k <= V; k++) {
        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                if(D[i][k] != INTMAX && D[k][j] != INTMAX) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    // STDOUT
    for(int r = 1; r <= V; r++) {
        for(int c = 1; c < V; c++) {
            cout << (D[r][c] == INTMAX ? 0 : D[r][c]) << ' ';
        }
        cout << (D[r][V] == INTMAX ? 0 : D[r][V]) << '\n';
    }

    return 0;
}
