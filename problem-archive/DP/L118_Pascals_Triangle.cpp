#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output = {{1}};

        for (int rowIdx = 2; rowIdx <= numRows; rowIdx++) {
            vector<int> row;
            vector<int> prev = output.back();
            for (int cell = 0; cell < rowIdx; cell++) {
                if (cell == 0 || cell == prev.size()) {
                    row.push_back(1);
                } else {
                    row.push_back(prev[cell - 1] + prev[cell]);
                }
            }
            output.push_back(row);
        }

        return output;
    }
};

struct Testing {
    int numRows;
    vector<vector<int>> output;
    static const int TSIZE = 2;
};

int main() {
    Testing t[Testing::TSIZE] = {
        Testing{5, {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}}},
        Testing{1, {{1}}},
    };

    Solution s;
    for(const auto& tcase : t) {
        auto output = s.generate(tcase.numRows);
        if (output != tcase.output) {
            cout << "FAIL" << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
