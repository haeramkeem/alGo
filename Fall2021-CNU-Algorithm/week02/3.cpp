#include <iostream>
#include <vector>

using namespace std;

long unsigned int nEnd; // 피라미드의 층수를 저장할 global 변수

/**
 * 벡터의 원소 합을 구하는 함수
 */
long unsigned int sum(vector<long unsigned int> vecInput) {
    long unsigned int nRes = 0;
    for(long unsigned int i = 0; i < vecInput.size(); i++) {
        nRes += vecInput[i]; // 벡터에서 값을 하나씩 꺼내 축적해줌
    }
    return nRes;
}

/**
 * 피라미드의 무게를 재귀적으로 구하기 위한 함수
 */
long unsigned int pyramid(vector<long unsigned int> vecInput, long unsigned int nAcc, long unsigned int nPhase) {
    if(nPhase == nEnd) { // 주어진 층수에 도달하면 지금까지 구한 무게를 반환
        return nAcc;
    } else {
        vector<long unsigned int> vecNext; // 현재 층의 원소들을 저장할 벡터
        vecNext.push_back(1); // 벡터에 1을 넣어줌
        for(long unsigned int i = 0; i < vecInput.size() - 1; i++) {
            vecNext.push_back(vecInput[i] + vecInput[i + 1]); // 해당 원소 바로 윗층에 있는 두 원소의 값을 더하여 현재 층의 원소 값을 구해냄
        }
        vecNext.push_back(1); // 벡터에 1을 넣어서 현재 층을 마무리함
        // 현재 층을 다음 층으로 전달하고 현재 층의 무게를 지금까지 구한 무게에 더해주며 층을 한단계 올려줌
        return pyramid(vecNext, nAcc + sum(vecNext), nPhase + 1);
    }
}

int main() {
    cin >> nEnd;
    vector<long unsigned int> vecInit;
    vecInit.push_back(1); // 피라미드의 맨 꼭대기에는 1밖에 없으므로 1을 넣어준 뒤
    cout << pyramid(vecInit, 1, 1) << endl; // 다음 층부터 연산하도록 지시
    return 0;
}