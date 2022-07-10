/**
 * Leetcode 746) Min cost climbing stairs
 * @see https://leetcode.com/problems/min-cost-climbing-stairs/
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> cache = cost;

        for(int ri = size - 3; ri >= 0; ri--) {
            cache[ri] = cost[ri] + min(cache[ri + 1], cache[ri + 2]);
        }

        return min(cache[0], cache[1]);
    }
};

struct Testing {
    vector<int> input;
    int output;
    static const int TCASE_SIZE = 2;
};

int main() {
    Testing t[Testing::TCASE_SIZE] = {
        Testing{{10,15,20}, 15},
        Testing{{1,100,1,1,1,100,1,1,100,1}, 6},
    };

    Solution s;
    for (auto& tcase : t) {
        auto res = s.minCostClimbingStairs(tcase.input);
        if (res != tcase.output) {
            cout << "FAIL\n";
            cout << "Want: " << tcase.output << endl;
            cout << "Got: " << res << endl;
            return 1;
        }
    }

    cout << "ok\n";
    return 0;
}
