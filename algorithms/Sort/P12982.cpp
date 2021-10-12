/**
 * Programmers 12982) https://programmers.co.kr/learn/courses/30/lessons/12982
 * 
 * Sort
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int nCnt = 0;
    for(const auto& el : d) {
        budget -= el;
        if(budget < 0) { break; }
        nCnt++;
    }
    return nCnt;
}

struct Testing {
    vector<int> d;
    int budget;
    int out;
};

const int TCASE_SIZE = 2;

int main() {
    Testing t[TCASE_SIZE] {
        Testing{{1, 3, 2, 5, 4}, 9, 3},
        Testing{{2, 2, 3, 3}, 10, 4},
    };
    for(const auto& tcase : t) {
        auto res = solution(tcase.d, tcase.budget);
        if(res != tcase.out) {
            cout << "FAIL: want " << tcase.out << ", got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}