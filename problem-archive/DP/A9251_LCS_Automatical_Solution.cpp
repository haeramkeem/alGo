#include <iostream>
#include <vector>
#include <array>

using namespace std;

int N1, N2;
vector<vector<int>> dp;
array<vector<int>, 26> prep;

int rec(string& s1, string& s2, const int& idx1, const int& idx2) {
    if(idx1 >= N1 || idx2 >= N2) {
        return 0;
    } else if(dp[idx1][idx2] != 0) {
        return dp[idx1][idx2];
    }

    int nmax = 0;

    // When idx2 is included
    for(const auto& next : prep[s2[idx2] - 'A']) {
        if(next >= idx1) {
            nmax = max(nmax, 1 + rec(s1, s2, next + 1, idx2 + 1));
            break;
        }
    }

    // When idx2 is not included
    return dp[idx1][idx2] = max(nmax, rec(s1, s2, idx1, idx2 + 1));
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    N1 = s1.size();
    N2 = s2.size();
    dp.resize(N1, vector<int>(N2, 0));

    for(int i = 0; i < N1; i++) {
        prep[s1[i] - 'A'].push_back(i);
    }

    cout << rec(s1, s2, 0, 0) << endl;
    return 0;
}
