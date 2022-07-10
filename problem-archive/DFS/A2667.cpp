/**
 * BOJ2667) https://www.acmicpc.net/problem/2667
 *
 * Counting Apartment
 *
 * Recursion DFS
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vecMap;
int nSize;
int nCnt;

void visit(int nR, int nC) {
    vecMap[nR][nC] = 0;
    nCnt++;
    if(0 <= nR - 1 && vecMap[nR - 1][nC] == 1) { visit(nR - 1, nC); }
    if(nC + 1 < nSize && vecMap[nR][nC + 1] == 1) { visit(nR, nC + 1); }
    if(nR + 1 < nSize && vecMap[nR + 1][nC]) { visit(nR +1, nC); }
    if(0 <= nC - 1 && vecMap[nR][nC - 1] == 1) { visit(nR, nC - 1); }
}

int main() {
    string strInTemp;
    cin >> nSize;
    vecMap.reserve(nSize);
    vector<int> vecRes;
    for(int i = 0; i < nSize; i++) {
        cin >> strInTemp;
        vector<int> vecInTemp(nSize);
        for(int j = 0; j < nSize; j++) {
            vecInTemp[j] = strInTemp[j] - 48;
        }
        vecMap.push_back(vecInTemp);
    }

    for(int nR = 0; nR < nSize; nR++) {
        for(int nC = 0; nC < nSize; nC++) {
            if(vecMap[nR][nC] == 1) {
                nCnt = 0;
                visit(nR, nC);
                vecRes.push_back(nCnt);
            }
        }
    }
    sort(vecRes.begin(), vecRes.end());
    cout << vecRes.size() << '\n';
    for(const auto& el : vecRes) {
        cout << el << '\n';
    }
    return 0;
}