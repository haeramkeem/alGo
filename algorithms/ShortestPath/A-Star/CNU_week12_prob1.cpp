#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <queue>

using namespace std;

#define ROW 0
#define COL 1

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
array<int, 2> start, endd;

struct Coords {
    //  Each Coordinate contains
    //      1. Row index
    //      2. Column index
    //      3. G - Cost for reaching current coordinate
    //      4. H - Heuristic, Estimated additional cost to reach to the destination
    int row, col, G, H;

    //  For this problem, we use Euclidean distance with D of 1 for Heuristic
    //      For more information for Heuristics:
    //      http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html
    Coords(const int& r, const int& c, const int& g): row(r), col(c), G(g) {
        int dr = r - endd[ROW];
        int dc = c - endd[COL];
        H = sqrt(dr*dr + dc*dc);
    }

    //  Sum of G and H is used to compare two coordinates
    //      It's because G means cost to reaching this coordinate and
    //      H means estimated additional cost to destination
    //      So G + H means estimated total cost
    bool operator<(const Coords& c) const { return this->G + this->H < c.G + c.H; }
    bool operator>(const Coords& c) const { return this->G + this->H > c.G + c.H; }
    bool operator==(const Coords& c) const { return this->G + this->H == c.G + c.H; }
};

int main() {
    int R, C, ice;
    cin >> R >> C >> ice;

    vector<vector<int>> matrix(R, vector<int>(C));
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for(int r = 0; r < R; r++) {
        string line;
        cin >> line;
        for(int c = 0; c < C; c++) {
            switch(line[c]) {
                case 'S' :
                    matrix[r][c] = 0;
                    start = { r, c };
                    visited[r][c] = true;
                    break;
                case 'E' :
                    matrix[r][c] = 0;
                    endd = { r, c };
                    break;
                default:
                    matrix[r][c] = line[c] - '0';
            }
        }
    }

    //  A* Algorithm uses priority queue to pick coordinate that has smallest G + H
    priority_queue<Coords, vector<Coords>, greater<Coords>> pq;
    pq.push(Coords(start[ROW], start[COL], 0));

    while(!pq.empty()) {
        auto h = pq.top();
        pq.pop();

        if(h.row == endd[ROW] && h.col == endd[COL]) {
            ice -= h.G;
            break;
        }

        for(int d = 0; d < 4; d++) {
            int nr = h.row + dr[d];
            int nc = h.col + dc[d];
            if(0 <= nr && nr < R && 0 <= nc && nc < C) {

                //  Check visit status
                if(!visited[nr][nc]) {

                    //  Update G of next coordinate
                    //      Let sum of current coordinate's G and next coordinate's cost be next coordinate's G
                    pq.push(Coords(nr, nc, h.G + matrix[nr][nc]));
                    visited[nr][nc] = true;
                }
            }
        }
    }

    if(ice < 0) {
        cout << "FAIL" << endl;
    } else {
        cout << ice << endl;
    }

    return 0;
}
