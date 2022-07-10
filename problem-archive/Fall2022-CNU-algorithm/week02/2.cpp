#include <iostream>

using namespace std;

/**
 * 유클리드 호제법을 이용해 최대공약수를 재귀적으로 구하기 위한 함수
 */
int solve(int nI, int nJ) {
    int nRemain = nI % nJ;
    if(nRemain == 0) { // 나머지가 0일 경우에 제수를 반환
        return nJ;
    } else {
        return solve(nJ, nRemain); // 그렇지 않은 경우에 제수와 나머지를 재귀적으로 호제법을 적용함
    }
}

int main() {
    int nI, nJ;
    cin >> nI >> nJ;
    cout << solve(nI, nJ) << endl;
}