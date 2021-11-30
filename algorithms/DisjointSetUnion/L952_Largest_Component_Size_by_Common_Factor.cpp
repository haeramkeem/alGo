/**
 * Leetcode 952) https://leetcode.com/problems/largest-component-size-by-common-factor/
 *
 * Largest Component Size by Common Factor
 *
 * Unsolved(Time out)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* ----- Solution ----- */
#define umap unordered_map
class Solution {
    umap<int, int> par;
    umap<int, int> rank;

    void init(const vector<int>& nums) {
        for(const auto& num : nums) {
            par[num] = num;
            rank[num] = 0;
        }
    }

    int rootOf(const int& num) {
        if(par[num] == num) { return num; }
        return rootOf(par[num]);
    }

    void unionTwo(const int& arg1, const int& arg2) {
        int root1 = rootOf(arg1), root2 = rootOf(arg2);
        if(rank[root1] > rank[root2]) {
            par[root2] = root1;
        } else {
            par[root1] = root2;
            if(rank[root1] == rank[root2]) {
                rank[root2]++;
            }
        }
    }

    int euclid(const int& arg1, const int& arg2) {
        int nmax = max(arg1, arg2), nmin = min(arg1, arg2);
        if(nmax % nmin == 0) {
            return nmin;
        }
        return euclid(nmin, nmax % nmin);
    }
public:
    int largestComponentSize(vector<int>& nums) {
        int N = nums.size();

        init(nums);
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(euclid(nums[i], nums[j]) > 1) {
                    unionTwo(nums[i], nums[j]);
                }
            }
        }

        int nmax = 0;
        umap<int, int> cnt;
        for(const auto& num : nums) {
            int root = rootOf(num);
            if(cnt.count(root) == 0) { cnt[root] = 0; }
            cnt[root]++;
            nmax = max(nmax, cnt[root]);
        }

        return nmax;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> nums;
    int outp;
    Testing(vector<int> n, int o): nums(n), outp(o) {}
    const static int SIZE = 3;
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({4,6,15,35}, 4),
        Testing({20,50,9,63}, 2),
        Testing({2,3,6,7,4,12,21,39}, 8),
    };

    Solution s;

    for(auto& tcase : t) {
        int res = s.largestComponentSize(tcase.nums);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
