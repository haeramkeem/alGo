/**
 * https://www.acmicpc.net/problem/1181
 *
 * C++ Standard Sort
 * 
 * ref: vector::erase, algorithm/unique
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int nNum;
    cin >> nNum;

    vector<string> vecInput(nNum);
    for(int i = 0; i < nNum; i++) {
        cin >> vecInput[i];
    }

    sort(vecInput.begin(), vecInput.end(), [](string str1, string str2) {
        if(str1.size() == str2.size()) {
            return str1 < str2;
        } else {
            return str1.size() < str2.size();
        }
    });

    vecInput.erase(unique(vecInput.begin(), vecInput.end()), vecInput.end());

    for(auto strEl : vecInput) {
        cout << strEl << endl;
    }
}