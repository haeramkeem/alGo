/**
 * Leetcode 1306) https://leetcode.com/problems/jump-game-iii/
 *
 * Jump Game III
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
    int N;
    vector<bool> visited;
    bool canReachImpl(vector<int>& arr, const int& cur) {
        visited[cur] = true;
        if(arr[cur] == 0) {
            return true;
        }
        int next = cur + arr[cur];
        if(0 <= next && next < N && !visited[next] && canReachImpl(arr, next)) {
            return true;
        }
        next = cur - arr[cur];
        if(0 <= next && next < N && !visited[next] && canReachImpl(arr, next)) {
            return true;
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        N = arr.size();
        visited.clear();
        visited.resize(N, false);
        return canReachImpl(arr, start);
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> arr;
    int start;
    bool outp;
    static const int SIZE = 4;
    Testing(vector<int> a, int s, bool o): arr(a), start(s), outp(o) {}
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({4,2,3,0,3,1,2}, 5, true),
        Testing({4,2,3,0,3,1,2}, 0, true),
        Testing({3,0,2,1,2}, 2, false),
        Testing({58,48,64,36,19,19,67,13,32,2,59,50,29,68,50,0,69,31,54,20,22,43,30,9,68,71,20,22,48,74,2,65,27,54,30,5,66,24,64,68,9,31,50,59,15,72,6,49,11,71,12,61,5,66,30,1,2,39,59,35,53,21,76,17,71,40,68,57,64,53,70,21,50,49,25,63,35}, 46, false),
    };

    Solution s;
    for(auto& tcase : t) {
        auto res = s.canReach(tcase.arr, tcase.start);
        if(res != tcase.outp) {
            cout << "FAIL: want " << boolalpha << tcase.outp << " got " << boolalpha << res << endl;
            return 1;
        }
    }

    cout << "ok\n";
    return 0;
}
