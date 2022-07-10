#include <iostream>

using namespace std;

/**
 * 계단의 갯수인 nN과 한번에 올라갈 수 있는 양인 nM을 인자로 줘 경우의 수를 세도록 함
 */
int solve(int nN, int nM) {
    if(nM <= 1) {
        return 1; // 계단의 갯수가 1보다 같거나 작으면 한번에 올라 갈 수 있음
    } else if(nM > nN) {
        return solve(nN, nN); // 한번에 올라갈 수 있는 계단의 최대가 계단의 수보다 크면 최대 계단의 수만큼 올라갈 수 있는것이나 마찬가지
    } else {
        int nRes = 0; // 한번에 올라갈 수 있는 계단의 수가 1일때부터 순차적으로 계산해 그 결과를 축적하기 위한 변수
        for(int i = 1; i <= nM; i++) {
            // 1 <= i <= nM인 i에 대해 먼저 i개의 계단을 올라간 뒤 남은 계단만큼을 한번에 최대 nM개 올라갈 수 있는 상태로 경우의 수를 재귀적으로 구함
            // i개의 계단을 먼저 올라가면 남은 계단은 nN - i개 일 것이고 한번에 올라갈 수 있는 계단의 최대 갯수는 여전히 nM이므로 이때의 경우의 수를 구함
            nRes += solve(nN - i, nM);
        }
        return nRes;
    }
}

int main() {
    int nN, nM;
    cin >> nN >> nM;
    cout << solve(nN, nM) << endl;
}