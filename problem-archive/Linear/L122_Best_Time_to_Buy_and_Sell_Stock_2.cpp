/**
 * Leetcode 122) https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 *
 * Best Time to Buy and Sell Stock II
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int before = prices[0], N = prices.size(), buy = -1, acc = 0;
        bool isDecline = true;
        for(int i = 1; i < N; i++) {
            if(before < prices[i]) {
                if(isDecline) {
                    isDecline = false;
                    buy = i - 1;
                }
            } else {
                isDecline = true;
                if(buy >= 0) {
                    acc += before - prices[buy];
                    buy = -1;
                }
            }
            before = prices[i];
        }
        if(buy >= 0) {
            acc += before - prices[buy];
        }

        return acc;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> prices;
    int outp;
};

const int TCASE_SIZE = 3;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{{7,1,5,3,6,4}, 7},
        Testing{{1,2,3,4,5}, 4},
        Testing{{7,6,4,3,1}, 0},
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.maxProfit(tcase.prices);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
