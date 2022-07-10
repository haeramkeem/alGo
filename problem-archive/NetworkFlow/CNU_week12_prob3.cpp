#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXINT 2147483647

int main() {
    int N;
    cin >> N;

    // 간선의 용량을 저장
    vector<vector<int>> capp(N, vector<int>(N, 0));
    // 간선에 흐르는 유량을 저장
    vector<vector<int>> flow(N, vector<int>(N, 0));
    // 노드 연결 관계 저장
    vector<vector<int>> conn(N);

    // 자료구조 초기화
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int c;
            cin >> c;
            if(c > 0) {
                capp[i][j] += c;
                conn[i].push_back(j);
                conn[j].push_back(i);
            }
        }
    }

    int tot = 0;
    const int beg = 0, endd = N - 1;
    while(true) {
        // 시작지점에서 종료지점까지의 경로를 하나 선택함

        // 어떤 노드를 방문하기 바로 직전에 방문했던 노드를 저장하는 방식으로 경로를 저장함
        vector<int> prev(N, -1);

        // 시작지점부터 BFS로 탐색
        queue<int> q;
        q.push(beg);
        // prev[endd] == -1이라면 아직 목적지까지 도달한것이 아니므로
        while(!q.empty() && prev[endd] == -1) {
            auto curr = q.front();
            q.pop();
            for(auto& next : conn[curr]) {
                // 현재 노드와 연결된 다음 노드가 방문한 적이 없어야 하고
                if(prev[next] == -1) {
                    // 현재 노드에서 다음 노드로 가는 간선의 용량이 유량보다 많아야 됨
                    if(capp[curr][next] > flow[curr][next]) {
                        prev[next] = curr;
                        // 다음 노드가 목적지일 경우 break를 걸어 제일 먼저 찾은 경로를 검토하게 함
                        if(next == endd) { break; }
                        q.push(next);
                    }
                }
            }
        }

        // 경로상의 모든 간선에 대해 유량이 용량보다 작은 경로를 찾지 못한 경우
        if(prev[endd] == -1) { break; }

        // 찾은 경로에서 추가적으로 흘려보낼 수 있는 유량의 양을 계산함
        int nextFlow = MAXINT;
        for(auto it = endd; it != beg; it = prev[it]) {
            // 경로상의 (용량 - 유량)의 최솟값을 구하면 그것이 모든 간선을 통과할 수 있는 유량이 됨
            nextFlow = min(nextFlow, capp[prev[it]][it] - flow[prev[it]][it]);
        }

        // 경로상의 모든 간선에 유량을 추가함
        for(auto it = endd; it != beg; it = prev[it]) {
            flow[prev[it]][it] += nextFlow;
            // 한방향으로 유체가 흐른다는 것은 반대방향으로 음의 유량이 흐른다고도 해석할 수 있으므로
            // 경로의 간선에 대해 반대방향으로 음의 유량을 더해줌
            flow[it][prev[it]] -= nextFlow;
        }

        // 총 흐르고 있는 유량의 크기를 더해줌
        tot += nextFlow;
    }

    // 결과 출력
    cout << tot << endl;
    return 0;
}
