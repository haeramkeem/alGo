/**
 * Leetcode 368) https://leetcode.com/problems/largest-divisible-subset/
 *
 * Largest Divisible Subset
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
    int N;
    vector<vector<int>> dp;
    vector<int> solve(vector<int>& nums, const int& start) {
        if(dp[start].size() != 0) {
            return dp[start];
        }
        vector<int> longest;
        for(int next = start + 1; next < N; next++) {
            if(nums[next] % nums[start] == 0) {
                auto res = solve(nums, next);
                if(longest.size() < res.size()) {
                    longest = res;
                }
            }
        }
        longest.push_back(nums[start]);
        dp[start] = longest;
        return longest;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        N = nums.size();
        sort(nums.begin(), nums.end());
        dp = vector<vector<int>>(N);

        vector<int> longest;
        for(int i = 0; i < N; i++) {
            auto res = solve(nums, i);
            if(res.size() > longest.size()) {
                longest = res;
            }
        }

        sort(longest.begin(), longest.end());
        return longest;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums;
    vector<int> outp;
    static void print(vector<int> tar) {
        cout << "{ ";
        for(const auto& el : tar) {
            cout << el << ' ';
        }
        cout << "}\n";
    }
};

const int TCASE_SIZE = 3;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{{1,2,3}, {1,2}},
        Testing{{1,2,4,8}, {1,2,4,8}},
        Testing{{5,9,18,54,108,540,90,180,360,720}, {9,18,90,180,360,720}},
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.largestDivisibleSubset(tcase.nums);
        if(res != tcase.outp) {
            cout << "FAIL\nwant: ";
            Testing::print(tcase.outp);
            cout << "got: ";
            Testing::print(res);
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
