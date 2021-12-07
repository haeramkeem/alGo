/**
 * BOJ 12865) https://www.acmicpc.net/problem/12865
 *
 * Knapsack Problem
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define WEIGHT 0
#define VALUE 1

int main() {
    TOOFAST;
    int N, K;
    cin >> N >> K;

    // Use 1-index for convenience
    vector<array<int, 2>> items(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> items[i][WEIGHT] >> items[i][VALUE];
    }

    // dp[i][w] means
    //  MAXIMUM value for
    //      range 1 ~ `i` items
    //      weight limit `w`
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    int nmax = 0;

    // Reccurence formula for this problem is
    //  MaxValueOf(lastItem, weightLimit) {
    //      if WeightOf(lastItem) > weightLimit {
    //          return MaxValueOf(lastItem - 1, weightLimit) --> When last item's weight is bigger than weight limit, drop it
    //      } else {
    //          return max(
    //              ValueOf(lastItem) + MaxValueOf(lastItem - 1, weightLimit - WeightOf(lastItem)),
    //              MaxValueOf(lastItem - 1, weightLimit),
    //          ) --> Choose bigger one between (Case when last item is added to knapsack) and (Case when drop the last item)
    //      }
    //  }
    for(int i = 1; i <= N; i++) {
        for(int w = 1; w <= K; w++) {
            if(items[i][WEIGHT] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(items[i][VALUE] + dp[i - 1][w - items[i][WEIGHT]], dp[i - 1][w]);
            }
            nmax = max(nmax, dp[i][w]);
        }
    }

    cout << nmax << '\n';
    return 0;
}
