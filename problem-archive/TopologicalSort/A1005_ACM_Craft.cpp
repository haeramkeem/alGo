/**
 * BOJ 1005) https://www.acmicpc.net/problem/1005
 *
 * ACM Craft
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define MAX 1000
#define uset unordered_set
#define NODE 0
#define BEG 1
#define END 2

int main() {
    TOOFAST;
    int tcaseSize;
    cin >> tcaseSize;
    while(tcaseSize--) {
        int N, K;
        cin >> N >> K;

        vector<int> ctime(N);
        uset<int> startPoints;
        for(int i = 0; i < N; i++) {
            cin >> ctime[i];
            startPoints.insert(i);
        }

        vector<vector<int>> nextIs(MAX);
        vector<vector<int>> beforeIs(MAX);
        for(int i = 0; i < K; i++) {
            int s, d;
            cin >> s >> d;
            s--; d--;
            nextIs[s].push_back(d);
            beforeIs[d].push_back(s);
            if(startPoints.count(d) != 0) {
                startPoints.erase(d);
            }
        }

        int end;
        cin >> end;

        queue<vector<int>> q;
        for(auto it = startPoints.begin(); it != startPoints.end(); it++) {
            q.push({*it, 0, ctime[*it]});
        }

        vector<vector<int>> completed(MAX);
        while(!q.empty()) {
            auto h = q.front();
            q.pop();
            completed[h[NODE]] = h;
            for(const auto& next : nextIs[h[NODE]]) {
                bool isAllCompleted = true;
                int dtime = 0;
                for(const auto& depend : beforeIs[next]) {
                    if(completed[depend].empty()) {
                        isAllCompleted = false;
                    } else {
                        dtime = max(dtime, completed[depend][END]);
                    }
                }
                if(isAllCompleted) {
                    q.push({next, dtime, dtime + ctime[next]});
                }
            }
        }
        cout << completed[end - 1][END] << '\n';
    }
    return 0;
}
