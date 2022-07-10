/**
 * Leetcode 986) https://leetcode.com/problems/interval-list-intersections/
 *
 * Interval List Intersections
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.size() == 0 || secondList.size() == 0) { return {}; }
        auto fit = firstList.begin(), sit = secondList.begin();
        vector<vector<int>> res;

        while(fit < firstList.end() && sit < secondList.end()) {
            if((*fit)[0] > (*sit)[1]) {
                sit++;
            } else if((*fit)[0] == (*sit)[1]) {
                res.push_back({(*fit)[0], (*sit)[1]});
                sit++;
            } else if((*sit)[1] < (*fit)[1]) {
                if((*sit)[0] < (*fit)[0]) {
                    res.push_back({(*fit)[0], (*sit)[1]});
                    sit++;
                } else {
                    res.push_back({(*sit)[0], (*sit)[1]});
                    sit++;
                }
            } else {
                if((*sit)[0] < (*fit)[0]) {
                    res.push_back({(*fit)[0], (*fit)[1]});
                    fit++;
                } else if((*sit)[0] < (*fit)[1]) {
                    res.push_back({(*sit)[0], (*fit)[1]});
                    fit++;
                } else if((*sit)[0] == (*fit)[1]) {
                    res.push_back({(*sit)[0], (*fit)[1]});
                    fit++;
                } else {
                    fit++;
                }
            }
        }
        return res;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<vector<int>> fl;
    vector<vector<int>> sl;
    vector<vector<int>> outp;
    static void print(vector<vector<int>>& vec) {
        cout << "{ ";
        for(const auto& el : vec) {
            cout << '{' << el[0] << ',' << el[1] << "} ";
        }
        cout << "}\n";
    }
};

const int TCASE_SIZE = 4;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{
            {{0,2},{5,10},{13,23},{24,25}},
            {{1,5},{8,12},{15,24},{25,26}},
            {{1,2},{5,5},{8,10},{15,23},{24,24},{25,25}},
        },
        Testing{
            {{1,3},{5,9}},
            {},
            {},
        },
        Testing{
            {},
            {{4,8},{10,12}},
            {},
        },
        Testing{
            {{1,7}},
            {{3,10}},
            {{3,7}},
        },
    };

    Solution s;
    for(auto& tcase : t) {
        auto res = s.intervalIntersection(tcase.fl, tcase.sl);
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
