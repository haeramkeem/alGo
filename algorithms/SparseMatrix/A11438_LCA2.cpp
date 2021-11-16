/**
 * BOJ 11438) https://www.acmicpc.net/problem/11438
 *
 * LCA 2
 *
 * ref: Binary Lifting
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int main() {
    toofast;
    int N;
    cin >> N;
    // 1. Make bidirectional connection.
    vector<vector<int>> conn(N + 1);
    for(int i = 0; i < N - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }

    // NOTICE: that size of expParent[i] is log2(N) + 2.
    //     as maximum count of binary lifting is log2(N) + 1, set size of expParent[i] to log2(N) + 2.
    //     so the last element of expParent[i] is always -1.
    int logN = log2(N) + 2; 

    // 2. Prepare Exponent-Parent Array.
    vector<vector<int>> expParent(N + 1, vector<int>(logN, -1));
    vector<int> height(N + 1);

    // 3. Calculate height & first parent for all nodes while traversing the nodes of tree.
    stack<int> stk;
    stk.push(1);
    vector<bool> visited(N + 1, false);
    while(!stk.empty()) {
        auto h = stk.top();
        stk.pop();
        visited[h] = true;
        for(const auto& next : conn[h]) {
            if(!visited[next]) {
                stk.push(next);
                expParent[next][0] = h;
                height[next] = height[h] + 1;
            }
        }
    }

    // 4. Fill Exponent-Parent Array
    for(int c = 1; c < logN; c++) {
        for(int r = 0; r < N + 1; r++) {
            int before = expParent[r][c - 1];
            // NOTICE: you need to check only expParent[r][c - 1].
            //     when expParent[before][c - 1] is -1, expParent[r][c] will be -1.
            //     so when calculating expParent[r][c + 1], as expParent[r][c] is -1, Skip assignment.
            //     thus, segmentation fault will not occur.
            if(before != -1) {
                expParent[r][c] = expParent[before][c - 1];
            }
        }
    }

    int M;
    cin >> M;
    for(int cnt = 0; cnt < M; cnt++) {
        int lower, upper;
        cin >> lower >> upper;
        if(height[lower] < height[upper]) {
            int t1 = lower;
            lower = upper;
            upper = t1;
        }

        // 5. Make both nodes the same height.
        int d = height[lower] - height[upper];
        for(int e = 0; e < logN && d != 0; e++) {
            if(d & (1 << e)) {
                lower = expParent[lower][e];
            }
        }
        
        if(lower == upper) {
            cout << lower << '\n';
        } else {
            // 6. Lift two nodes to directly below of target ancestor
            for(int e = logN - 1; e >= 0; e--) {
                int ljump = expParent[lower][e];
                int ujump = expParent[upper][e];
                if(ljump != -1 && ujump != -1 && ljump != ujump) {
                    lower = ljump;
                    upper = ujump;
                }
            }
            // 7. Parent of result node is a Lowest Common Ancestor.
            cout << expParent[lower][0] << '\n';
        }
    }
}
