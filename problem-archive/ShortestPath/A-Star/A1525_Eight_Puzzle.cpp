/**
 * BOJ 1525) https://www.acmicpc.net/problem/1525
 *
 * Eight Puzzle
 *
 * ref: A* Algorithm
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define uset unordered_set

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

struct State {
    int G, H;
    string matrix;
    State(): State(0, "") {}
    State(const int& g, const string& m): G(g), matrix(m) {
        H = 0;
        string dst = "123456780";
        for(int i = 0; i < 9; i++) {
            H += m[i] != dst[i] ? 1 : 0;
        }
    }
    bool operator<(const State& s) const { return this->G + this->H < s.G + s.H; }
    bool operator>(const State& s) const { return this->G + this->H > s.G + s.H; }
    bool operator==(const State& s) const { return this->G + this->H == s.G + s.H; }
};

int solve(const string& init) {
    uset<string> visited;

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push(State(0, init));
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        // Check Heuristic
        if(cur.H == 0) { return cur.G; }

        // Mark to visited
        visited.insert(cur.matrix);

        // Do next movement
        int zero = cur.matrix.find('0');
        int r = zero / 3, c = zero % 3;
        for(int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if(0 <= nr && nr < 3 && 0 <= nc && nc < 3) {
                string next = cur.matrix;
                swap(next[r * 3 + c], next[nr * 3 + nc]);
                if(visited.count(next) == 0) {
                    pq.push(State(cur.G + 1, next));
                }
            }
        }
    }
    return -1;
}

int main() {
    TOOFAST;

    string acc = "";
    acc.reserve(9);

    // STDIN
    int r, c;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            string strNum;
            cin >> strNum;
            acc += strNum;
        }
    }

    // STDOUT
    cout << solve(acc) << '\n';
    return 0;
}
