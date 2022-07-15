#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define marshal(y, x) ( 100 * (y) + (x) )
#define unmarshal_y(v) ( (v) / 100 )
#define unmarshal_x(v) ( (v) % 100 )
class Solution {
    vector<int> dx = { 0, 1, 0, -1 };
    vector<int> dy = { -1, 0, 1, 0 };
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int yEdge = grid.size();
        int xEdge = grid[0].size();

        int maxArea = 0;
        for (int y = 0; y < yEdge; y++) {
            for (int x = 0; x < xEdge; x++) {
                if (grid[y][x] == 1) {
                    // Init
                    int area = 0;
                    queue<int> q;
                    q.push(marshal(y, x));
                    grid[y][x] = 0;

                    // BFS
                    while (!q.empty()) {
                        int curY = unmarshal_y(q.front());
                        int curX = unmarshal_x(q.front());
                        area++;

                        for (int d = 0; d < 4; d++) {
                            int nextY = curY + dy[d];
                            int nextX = curX + dx[d];

                            if (0 <= nextY && nextY < yEdge
                                && 0 <= nextX && nextX < xEdge
                                && grid[nextY][nextX] == 1) {
                                q.push(marshal(nextY, nextX));
                                grid[nextY][nextX] = 0;
                            }
                        }

                        q.pop();
                    }

                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
};

struct Testing {
    vector<vector<int>> grid;
    int output;
    static const int TCASE_SIZE = 2;
};

int main() {
    Testing t[Testing::TCASE_SIZE] = {
        Testing{{
            {0,0,1,0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,1,1,0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,1,1,0,0,1,0,1,0,0},
            {0,1,0,0,1,1,0,0,1,1,1,0,0},
            {0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,1,1,0,0,0,0},
        }, 6},
        Testing{{
            {0,0,0,0,0,0,0,0},
        }, 0},
    };

    Solution s;

    for(auto& tcase : t) {
        auto output = s.maxAreaOfIsland(tcase.grid);
        if (output != tcase.output) {
            cout << "FAIL" << endl;
            cout << "Want: " << tcase.output << endl;
            cout << "Got: " << output << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
