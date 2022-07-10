/**
 * BOJ 17435) https://www.acmicpc.net/problem/17435
 *
 * Composite functions and queries
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int main() {
    toofast;
    int M;
    cin >> M;

    vector<vector<int>> sparse(M + 1, vector<int>(23, -1));
    for(int i = 1; i <= M; i++) {
        cin >> sparse[i][0];
    }

    for(int si = 1; si < 23; si++) {
        for(int fi = 1; fi <= M; fi++) {
            sparse[fi][si] = sparse[sparse[fi][si - 1]][si - 1];
        }
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int n, x;
        cin >> n >> x;
        for(int e = 0; e < 23; e++) {
            if(n & (1 << e)) {
                x = sparse[x][e];
            }
        }
        cout << x << '\n';
    }

    return 0;
}
