/**
 * BOJ 1920) https://www.acmicpc.net/problem/1920
 * 
 * Set
 */

#include <iostream>
#include <unordered_set>

using namespace std;
#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int main() {
    toofast;
    int nN, nM, nTemp;
    unordered_set<int> setInp;
    cin >> nN; for(int i = 0; i < nN; i++) { cin >> nTemp; setInp.insert(nTemp); }
    cin >> nM; for(int i = 0; i < nM; i++) { cin >> nTemp; cout << setInp.count(nTemp) << '\n'; }

    return 0;
}