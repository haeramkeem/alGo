/**
 * Leetcode 739) https://leetcode.com/problems/daily-temperatures/
 *
 * Daily Temperatures
 *
 * ref: Leetcode 42 - Trapping Water
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* ----- Solution ----- */
class Solution {
    struct TempDay {
        int temp, idx;
    };
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        stack<TempDay> s;
        for(int i = 0; i < N; i++) {
            int temp = temperatures[i];
            temperatures[i] = 0;
            while(!s.empty() && temp > s.top().temp) {
                auto h = s.top();
                s.pop();
                temperatures[h.idx] = i - h.idx;
            }
            s.push(TempDay{temp, i});
        }
        return temperatures;
    }
};

/* ----- Testing ----- */
const int TCASE_SIZE = 3;

struct Testing {
    vector<int> temperatures;
    vector<int> outp;
    static void print(vector<int>& vec) {
        for(const auto& el : vec) {
            cout << el << ' ';
        }
        cout << endl;
    }
};

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{{73,74,75,71,69,72,76,73}, {1,1,4,2,1,1,0,0}},
        Testing{{30,40,50,60}, {1,1,1,0}},
        Testing{{30,60,90}, {1,1,0}},
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.dailyTemperatures(tcase.temperatures);
        if(res != tcase.outp) {
            cout << "FAIL:\nwant: ";
            Testing::print(tcase.outp);
            cout << "got: ";
            Testing::print(res);
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
