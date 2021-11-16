/**
 * BOJ 11437) https://www.acmicpc.net/problem/11437
 *
 * LCA
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr)
#define MAX 16

int main() {
    TOOFAST;
    int N;
    cin >> N;

    vector<vector<int>> conn(N + 1);
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    vector<vector<int>> sparse(N + 1, vector<int>(MAX, -1));
    vector<int> height(N + 1, 0);

    vector<bool> visited(N + 1, false);
    visited[1] = true;

    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int h = q.front();
        q.pop();
        for(const auto& next : conn[h]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                height[next] = height[h] + 1;
                sparse[next][0] = h;
            }
        }
    }

    for(int si = 1; si < MAX; si++) {
        for(int fi = 1; fi <= N; fi++) {
            if(sparse[fi][si - 1] != -1) {
                sparse[fi][si] = sparse[sparse[fi][si - 1]][si - 1];
            }
        }
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if(height[u] < height[v]) {
            int t = u;
            u = v;
            v = t;
        }

        int dis = height[u] - height[v];
        for(int e = 0; e < MAX && dis != 0; e++) {
            if(dis & (1 << e)) {
                u = sparse[u][e];
            }
        }
        
        if(u == v) {
            cout << u << '\n';
        } else {
            for(int e = MAX - 1; e >= 0; e--) {
                if(sparse[u][e] != sparse[v][e]) {
                    u = sparse[u][e];
                    v = sparse[v][e];
                }
            }
            cout << sparse[u][0] << '\n';
        }
    }

    return 0;
}
