/**
 * Leetcode 1200) https://leetcode.com/problems/minimum-absolute-difference/
 *
 * Minimum Absolute Difference
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, vector<vector<int>>> mp;
        for(auto it = arr.begin(); it < arr.end() - 1; it++) {
            mp[*(it + 1) - *it].push_back({*it, *(it + 1)});
        }
        return mp.begin()->second;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> arr;
    vector<vector<int>> outp;
    static const int SIZE = 3;
    Testing(): Testing({}, {}) {}
    Testing(vector<int> a, vector<vector<int>> o): arr(a), outp(o) {}
    static void print(vector<vector<int>> arg) {
        cout << "{ ";
        for(const auto& el : arg) {
            cout << "{ ";
            for(const auto& num : el) {
                cout << num << ' ';
            }
            cout << "} ";
        }
        cout << "}\n";
    }
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({4,2,1,3}, {{1,2},{2,3},{3,4}}),
        Testing({1,3,6,10,15}, {{1,3}}),
        Testing({3,8,-10,23,19,-4,-14,27}, {{-14,-10},{19,23},{23,27}}),
    };

    for(auto& tcase : t) {
        Solution s;
        auto res = s.minimumAbsDifference(tcase.arr);
        if(res != tcase.outp) {
            cout << "FAIL\nwant: ";
            Testing::print(tcase.outp);
            cout << "got: ";
            Testing::print(res);
            return 1;
        }
    }

    cout << "ok\n";
    return 0;
}
