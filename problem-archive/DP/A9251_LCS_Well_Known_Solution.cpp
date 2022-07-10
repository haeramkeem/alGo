#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int N1, N2;
    N1 = s1.size();
    N2 = s2.size();

    vector<vector<int>> cache(N1 + 1, vector<int>(N2 + 1, 0));
    for(int i1 = 1; i1 <= N1; i1++) {
        for(int i2 = 1; i2 <= N2; i2++) {
            if(s1[i1 - 1] == s2[i2 - 1]) {

                // 
                cache[i1][i2] = cache[i1 - 1][i2 - 1] + 1;
            } else {
                cache[i1][i2] = max(cache[i1 - 1][i2], cache[i1][i2 - 1]);
            }
        }
    }

    cout << cache[N1][N2] << '\n';

    return 0;
}
