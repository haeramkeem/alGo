/**
 * CNU week13 prob2
 *
 * Knapsack
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int C, N;
    cin >> C >> N;
    
    // 물품의 무게를 1-index로 저장함
    vector<int> W(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> W[i];
    }

    // 물품의 가치를 1-index로 저장함
    vector<int> V(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> V[i];
    }
    
    // cache[i번째 물품][무게제한 w] == 1번째 ~ i번째 물품까지 고려했을때 무게제한 w내에서의 최대 가치
    vector<vector<int>> cache(N + 1, vector<int>(C + 1));

    // 모든 물품 범위와 무게제한에 대해 최대 가치를 저장함
    for(int i = 1; i <= N; i++) {
        for(int w = 1; w <= C; w++) {

            // 만약 물품 범위의 마지막 물품의 무게가 현재 무게제한보다 클 경우
            if(W[i] > w) {

                // 물품 범위의 마지막 물품을 가방에 넣지 않음
                cache[i][w] = cache[i - 1][w];

            // 만약 물품 범위의 마지막 물품의 무게가 현재 무게제한보다 작거나 같을 경우
            } else {

                // 마지막 물품을 가방에 넣었을때와 넣지 않았을때 중 가치가 큰것을 고름
                cache[i][w] = max(V[i] + cache[i - 1][w - W[i]], cache[i - 1][w]);
            }
        }
    }
    
    // 주어진 물품 범위와 무게 제한에 대한 가치의 최고값 출력
    cout << cache[N][C] << endl;
    return 0;
}
