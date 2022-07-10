/**
 * CNU week13 prob3
 *
 * Longest Common Subsequence
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int N1, N2;
    N1 = s1.size();
    N2 = s2.size();
    
    // cache[첫번째 문자열의 1-index i1][두번째 문자열의 1-index i2] ==
    //      첫번째 문자열의 1 ~ i1의 범위와
    //      두번째 문자열의 1 ~ i2의 범위를 고려한 LCS
    vector<vector<int>> cache(N1 + 1, vector<int>(N2 + 1, 0));

    // 모든 i1와 i2의 범위 조합에 대해 계산함
    for(int i1 = 1; i1 <= N1; i1++) {
        for(int i2 = 1; i2 <= N2; i2++) {

            // 만일 0-index로 변환한 i1의 문자와 i2의 문자가 같을 경우
            //  지금까지 이어져오던 LCS에 현재의 문자를 추가해야됨
            //      지금까지 이어져오던 LCS Stream은 현재의 동일한 두 문자를 제외한 이전의 범위의 LCS Stream이다
            //      따라서, 문자열 s1에 대한 1 ~ (i1 - 1)의 범위와
            //      문자열 s2에 대한 1 ~ (i2 - 1)의 범위에서의 LCS길이에 1을 추가한 값이
            //      1 ~ i1과 1 ~ i2의 범위에 대한 LCS의 길이가 됨
            if(s1[i1 - 1] == s2[i2 - 1]) {
                cache[i1][i2] = cache[i1 - 1][i2 - 1] + 1;

            // 만일 두 문자가 같지 않은 경우
            //      두 문자 각각을 제외했을때의 LCS 중 가장 긴것을 선택
            } else {
                cache[i1][i2] = max(cache[i1 - 1][i2], cache[i1][i2 - 1]);
            }
        }
    }
    
    cout << cache[N1][N2] << endl;
    return 0;
}
