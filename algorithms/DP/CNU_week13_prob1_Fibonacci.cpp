/**
 * CNU week13 prob1
 *
 * Fibonacci
 */

#include <iostream>
#include <vector>

using namespace std;

// 정수 오버플로우를 방지하기 위함
#define uint uint64_t

int main() {
    int N;
    cin >> N;

    // 모든 숫자를 0으로 초기화
    vector<uint> cache(N + 1, 0);

    // Fibonacci(1) = 1이므로
    cache[1] = 1;

    // Fibonacci(N)까지를 점화식을 이용해 계산함
    for(int i = 2; i <= N; i++) {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    // STDOUT
    cout << cache[N] << endl;
    
    return 0;
}
