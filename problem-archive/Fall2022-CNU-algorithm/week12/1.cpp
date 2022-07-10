#include <cstdlib>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <queue>

using namespace std;

#define ROW 0
#define COL 1
#define BEG -1
#define END -2

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
array<int, 2> start, endd;

// 좌표의 정보를 담는 구조체
struct Cor {
    int row, col, G, H;

    // 좌표 객체를 생성하면 Heuristic값이 자동으로 계산됨
    Cor(const int& r, const int& c, const int& g): row(r), col(c), G(g) {
        int dr = r - endd[ROW];
        int dc = c - endd[COL];
        H = sqrt(dr*dr + dc*dc);
    }

    // 좌표의 대소비교는 G와 Heuristic를 더한 값을 기준으로 수행됨
    bool operator<(const Cor& c) const { return this->G + this->H < c.G + c.H; }
    bool operator>(const Cor& c) const { return this->G + this->H > c.G + c.H; }
    bool operator==(const Cor& c) const { return this->G + this->H == c.G + c.H; }
};

int main() {
    int R, C, ice;
    cin >> R >> C >> ice;

    // 입력값으로 좌표평면을 초기화하고 방문체크용 배열도 초기화함
    vector<vector<int>> matrix(R, vector<int>(C));
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for(int r = 0; r < R; r++) {
        string line;
        cin >> line;
        for(int c = 0; c < C; c++) {
            switch(line[c]) {
                case 'S' : matrix[r][c] = BEG; start[ROW] = r; start[COL] = c; visited[r][c] = true; break;
                case 'E' : matrix[r][c] = END; endd[ROW] = r; endd[COL] = c; break;
                default: matrix[r][c] = line[c] - '0';
            }
        }
    }

    // 우선순위 큐를 생성하여 G + Heuristic값이 작은 좌표를 선택하도록 함
    priority_queue<Cor, vector<Cor>, greater<Cor>> pq;
    // 시작지점을 우선순위 큐에 넣어줌
    pq.push(Cor(start[ROW], start[COL], 0));
    while(!pq.empty()) {
        auto h = pq.top();
        pq.pop();

        // 현재 좌표가 종료지점이면 녹은 얼음의 양을 초기 얼음의 양에서 빼준 뒤 반복문을 빠져나옴
        if(matrix[h.row][h.col] == END) {
            ice -= h.G - END;
            break;
        }

        for(int d = 0; d < 4; d++) {
            int nr = h.row + dr[d];
            int nc = h.col + dc[d];
            if(0 <= nr && nr < R && 0 <= nc && nc < C) {
                // 현재좌표와 인접한 좌표가 방문하지 않은 좌표라면 우선순위 큐에 넣어주고 방문체크함
                if(!visited[nr][nc]) {
                    // G의 값으로 지금까지 녹은 얼음의 양과 해당 좌표로 갈 경우 녹는 얼음의 양의 합을 설정함
                    pq.push(Cor(nr, nc, h.G + matrix[nr][nc]));
                    visited[nr][nc] = true;
                }
            }
        }
    }

    // 결과 출력
    if(ice < 0) {
        cout << "FAIL" << endl;
    } else {
        cout << ice << endl;
    }

    return 0;
}
