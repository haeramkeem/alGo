/**
 * BOJ 11438) https://www.acmicpc.net/problem/11438
 *
 * LCA2
 *
 * Range Minimum Query
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr)

vector<int> E;
vector<int> L;
vector<int> H;
vector<int> segment;

vector<vector<int>> conn;
vector<bool> visited;
vector<int> height;

void dfs(const int& cur) {
    visited[cur] = true;
    E.push_back(cur);
    L.push_back(height[cur]);
    if(H[cur] == -1) {
        H[cur] = E.size() - 1;
    }

    for(const auto& next : conn[cur]) {
        if(!visited[next]) {
            height[next] = height[cur] + 1;
            dfs(next);
            E.push_back(cur);
            L.push_back(height[cur]);
        }
    }

}

int make(const int& l, const int& r, const int& treeIdx) {
    if(l == r) {
        segment[treeIdx] = l;
    } else {
        int m = (l + r) / 2;
        int ll = make(l, m, 2 * treeIdx + 1);
        int rr = make(m + 1, r, 2 * treeIdx + 2);
        segment[treeIdx] = L[ll] < L[rr] ? ll : rr;
    }
    return segment[treeIdx];
}

int findMin(const int& treeL, const int& treeR, const int& treeIdx, const int& l, const int& r) {
    if(treeR < l || r < treeL) { return -1; }
    if(l <= treeL && treeR <= r) { return segment[treeIdx]; }

    int m = (treeL + treeR) / 2;
    int ll = findMin(treeL, m, 2 * treeIdx + 1, l, r);
    int rr = findMin(m + 1, treeR, 2 * treeIdx + 2, l, r);

    if(ll == -1) { return rr; }
    if(rr == -1) { return ll; }
    return L[ll] < L[rr] ? ll : rr;
}

int main() {
    TOOFAST;
    int N;
    cin >> N;

    H = vector<int>(N + 1, -1);
    conn = vector<vector<int>>(N + 1);
    visited = vector<bool>(N + 1, false);
    height = vector<int>(N + 1, 0);
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    dfs(1);

    int S = L.size();
    segment = vector<int>(4 * S);
    make(0, S - 1, 0);

    int M;
    cin >> M;
    while(M--) {
        int u, v;
        cin >> u >> v;
        if(H[u] > H[v]) {
            int t = u;
            u = v;
            v = t;
        }

        cout << E[findMin(0, S - 1, 0, H[u], H[v])] << '\n';
    }
    
    return 0;
}
