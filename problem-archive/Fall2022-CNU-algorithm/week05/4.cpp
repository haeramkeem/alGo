#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int d) {
    sort(budgets.begin(), budgets.end());
    int avg = d / budgets.size();
    int splitter = 0;
    for(splitter = 0; splitter < budgets.size(); splitter++) {
        if(budgets[splitter] > avg) {
            break;
        } else {
            d -= budgets[splitter];
        }
    }
    return d / (budgets.size() - splitter);
}

struct Testing {
    vector<int> budgets;
    int m;
    int out;
};

const int TCASE_SIZE = 3;

int main() {
    Testing t[TCASE_SIZE] {
        Testing{{120, 110, 140, 150}, 485, 127},
        Testing{{120, 110, 140, 150}, 400, 100},
        Testing{{120, 110, 140, 150}, 550, 160},
    };
    for(const auto& tcase : t) {
        auto res = solution(tcase.budgets, tcase.m);
        if(res != tcase.out) {
            cout << "FAIL: want " << tcase.out << ", got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}