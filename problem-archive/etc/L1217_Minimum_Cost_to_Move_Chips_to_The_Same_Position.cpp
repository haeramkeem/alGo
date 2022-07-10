#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        if(position.size() < 2) { return 0; }
        position[1] = (position[0] % 2) + (position[1] % 2);
        position[0] = 2 - position[1];
        for(size_t i = 2; i < position.size(); i++) {
            position[position[i] % 2]++;
        }
        return min(position[0], position[1]);
    }
};

struct Testing {
    vector<int> position;
    int outp;
    Testing(vector<int> p, int o): position(p), outp(o) {}
    static const int SIZE = 4;
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({1,2,3}, 1),
        Testing({2,2,2,3,3}, 2),
        Testing({1,1000000000}, 1),
        Testing({3,3,1,2,2}, 2),
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.minCostToMoveChips(tcase.position);
        if(res != tcase.outp) {
            cout << "FAIL want " << tcase.outp << " got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
