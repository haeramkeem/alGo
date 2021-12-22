#include <iostream>

using namespace std;

/**
 * 피보나치 수열을 재귀적으로 구하기 위한 함수
 */
int pib(int nInput) {
    if(nInput == 0) { // 0번째 값에 대한 종료조건
        return 0;
    } else if(nInput < 3) { // 1번째, 2번째 값에 대한 종료조건
        return 1;
    } else {
        return pib(nInput - 1) + pib(nInput - 2); // n - 1, n - 2번째에 대한 결과를 재귀적으로 구하여 더함
    }
}

int main() {
    int nInput;
    cin >> nInput;
    cout << pib(nInput) << endl;
}