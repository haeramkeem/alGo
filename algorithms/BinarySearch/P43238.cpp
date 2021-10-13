/**
 * P43238) https://programmers.co.kr/learn/courses/30/lessons/43238#
 * 
 * Binary Search
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* ----- Solution ----- */
long long solution(int n, vector<int> times) {
    long long l = 0, r = n, max = -1, bound = 0, acc = 0, handle = 0;
    for(const auto& el : times) { if(max < el) { max = el; } }
    r *= max;
    while(l <= r) {
        bound = (l + r) / 2;
        acc = 0;
        for(const auto& el : times) {
            acc += bound / el;
        }
        if(acc < n) {
            l = bound + 1;
        } else {
            if(bound <= r) { max = bound; }
            r = bound - 1;
        }
    }
    return max;
}

/* ----- Testing ----- */
struct Testing {
    int n;
    vector<int> times;
    int out;
};

const int TCASE_SIZE = 2;

int main() {
    Testing t[TCASE_SIZE] {
        Testing{6, {7, 10}, 28},
        Testing{12, {7, 10, 11, 15}, 33},
    };
    for(const auto& tcase : t) {
        auto res = solution(tcase.n, tcase.times);
        if(res != tcase.out) {
            cout << "FAIL: want " << tcase.out << ", got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}