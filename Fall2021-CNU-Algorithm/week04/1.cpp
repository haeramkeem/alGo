#include <iostream>
#include <vector>

using namespace std;

void fnBubble(vector<char> vecIn, char& cAd, int& nCnt) {
    bool isChange = true;
    // 변경사항이 있고 정렬 횟수가 만료되지 않았을때까지 반복함
    while(isChange && nCnt > 0) {
        isChange = false;

        // 벡터의 첫 원소부터 n - 1 원소까지 탐색함
        for(auto it = vecIn.begin(); it < vecIn.end() - 1; it++) {

            // Ascending order 일때
            if(cAd == 'A') {

                // 앞의 원소가 더 크다면
                if(*it > *(it + 1)) {

                    // 두 값을 스왑하고 변경되었음으로 변경함
                    auto tmp = *it;
                    *it = *(it + 1);
                    *(it + 1) = tmp;
                    isChange = true;
                }

            // Descending order 일때
            } else if(cAd == 'D') {

                // 앞의 원소가 더 작다면
                if(*it < *(it + 1)) {

                    // 두 값을 스왑하고 변경되었음으로 변경함
                    auto tmp = *it;
                    *it = *(it + 1);
                    *(it + 1) = tmp;
                    isChange = true;
                }
            }
        }

        // 정렬 횟수를 1 감소시킴
        nCnt--;
    }
    for(auto el : vecIn) {
        cout << el << ' ';
    }
    cout << endl;
}

int main() {
    int nNum, nStep;
    char cAd;
    cin >> nNum >> nStep >> cAd;
    vector<char> vecIn(nNum);
    for(int i = 0; i < nNum; i++) {
        cin >> vecIn[i];
    }
    fnBubble(vecIn, cAd, nStep);
    return 0;
}