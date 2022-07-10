/**
 * Leetcode 85) https://leetcode.com/problems/maximal-rectangle/
 *
 * Maximal Rectangle
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
#define MAX 200
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) {
            return 0;
        }
        int R = matrix.size(), C = matrix[0].size();

        int nMax = 0;
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                if(matrix[r][c] == '1') {
                    int rr = r, dc = MAX;
                    for(; rr < R && matrix[rr][c] == '1'; rr++) {
                        int cc = c;
                        for(; cc < C && matrix[rr][cc] == '1'; cc++) {}
                        dc = min(dc, cc - c);
                        nMax = max(nMax, dc * (rr - r + 1));
                    }
                }
            }
        }
        return nMax;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<vector<char>> matrix;
    int outp;

    const static int SIZE = 5;
    
    Testing(vector<vector<char>> m, int o): matrix(m), outp(o) {}
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'},
        }, 6),
        Testing({}, 0),
        Testing({{'0'}}, 0),
        Testing({{'1'}}, 1),
        Testing({{'0','0'}}, 0),
    };

    Solution s;

    for(auto& tcase : t) {
        int res = s.maximalRectangle(tcase.matrix);
        if(res != tcase.outp) {
            cout << "FAIL: want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
