#include <iostream>
#include <vector>

using namespace std;

int nStep;
char cAd;

// Subvector를 병합하는 함수
void fnMerge(vector<char>& vecIn, vector<char>& vecLeft, vector<char>& vecRight) {
    // 만약 정렬 횟수가 만료되면 이후에는 Left와 Right를 Concatenate하여 반환함
    if(nStep <= 0) {
        copy(vecLeft.begin(), vecLeft.end(), vecIn.begin());
        copy(vecRight.begin(), vecRight.end(), vecIn.begin() + vecLeft.size());
        return;
    }

    // 정렬 횟수가 만료되지 않았을 때
    auto lit = vecLeft.begin(), rit = vecRight.begin();
    u_long i = 0;

    // Left와 Right를 전부 iterate하여 타겟 벡터가 전부 채워질때까지 동작함
    while(lit < vecLeft.end() && rit < vecRight.end() && i < vecIn.size()) {

        // Ascending order이고 Left의 iterated element가 작을 경우
        //     Left의 iterated element와 Right의 iterated element 중 더 작은 원소를 타겟 벡터에 먼저 넣어야 하므로
        //     Left의 iterated element를 타겟 벡터에 넣는다.
        // Descending order이고 Left의 원소가 클 경우
        //     Left의 iterated element와 Right의 iterated element 중 더 큰 원소를 타겟 벡터에 먼저 넣어야 하므로
        //     Left의 iterated element를 타겟 벡터에 넣는다.
        if((cAd == 'A' && *lit < *rit) || (cAd == 'D' && *lit > *rit)) {

            // 원소를 타겟 벡터에 넣음
            vecIn[i] = *lit;

            // Left의 iterated element를 넣었으므로 left-iterator를 전진시킨다.
            // 타겟 벡터에 원소를 넣었으므로 타겟 벡터의 iterate index도 1 증가시킨다.
            lit++; i++;

            // 만약 Left에 더 이상 원소가 남아있지 않을 경우에는 Right에 남아있는 원소를 전부 타겟 벡터에 순서를 유지하여 넣어준다.
            if(lit >= vecLeft.end()) {
                copy(rit, vecRight.end(), vecIn.begin() + i);
                rit = vecRight.end();
            }

        // Ascending order이고 Right의 iterated element가 작을 경우
        //     Left의 iterated element와 Right의 iterated element 중 더 작은 원소를 타겟 벡터에 먼저 넣어야 하므로
        //     Right의 iterated element를 타겟 벡터에 넣는다.
        // Descending order이고 Right의 원소가 클 경우
        //     Left의 iterated element와 Right의 iterated element 중 더 큰 원소를 타겟 벡터에 먼저 넣어야 하므로
        //     Right의 iterated element를 타겟 벡터에 넣는다.
        } else if((cAd == 'A' && *lit > *rit) || (cAd == 'D' && *lit < *rit)) {

            // 원소를 타겟 벡터에 넣음
            vecIn[i] = *rit;

            // Right의 iterated element를 넣었으므로 right-iterator를 전진시킨다.
            // 타겟 벡터에 원소를 넣었으므로 타겟 벡터의 iterate index도 1 증가시킨다.
            rit++; i++;

            // 만약 Right에 더 이상 원소가 남아있지 않을 경우에는 Left에 남아있는 원쏘를 전부 타겟 벡터에 순서를 유지하여 넣어준다.
            if(rit >= vecRight.end()) {
                copy(lit, vecLeft.end(), vecIn.begin() + i);
                lit = vecLeft.end();
            }
        }
    }

    // 정렬 횟수를 1 감소시킴
    nStep--;
}

// Vector를 정렬하는 함수
void fnSort(vector<char>& vecIn) {

    // 벡터의 크기가 2보다 작을 때는 정렬되어 있는것으로 간주함.
    if(vecIn.size() < 2) { return; }

    // 백터를 두개의 subvector로 나눈다.
    int nSep = vecIn.size() / 2;
    vector<char> vecLeft, vecRight;
    vecLeft.assign(vecIn.begin(), vecIn.begin() + nSep);
    vecRight.assign(vecIn.begin() + nSep, vecIn.end());

    // Left subvector와 Right subvector를 재귀적으로 정렬해준다.
    fnSort(vecLeft); fnSort(vecRight);

    // 정렬이 끝난 Left subvector와 Right subvector를 병합한다.
    fnMerge(vecIn, vecLeft, vecRight);
}

int main() {
    int nNum;
    cin >> nNum >> nStep >> cAd;
    vector<char> vecIn(nNum);
    for(int i = 0; i < nNum; i++) {
        cin >> vecIn[i];
    }
    fnSort(vecIn);
    for(auto el : vecIn) {
        cout << el << ' ';
    }
    cout << endl;
    return 0;
}