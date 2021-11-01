#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
	int dr[4] = {-1, 0, 1, 0};
	int dc[4] = {0, 1, 0, -1};

	void uncapture(vector<vector<char>>& board, const int& r, const int& c) {
		board[r][c] = 'o';
		for(int d = 0; d < 4; d++) {
			int nR = r + dr[d];
			int nC = c + dc[d];
			if(0 <= nR && nR < board.size() && 0 <= nC && nC < board[0].size() && board[nR][nC] == 'O') {
				uncapture(board, nR, nC);
			}
		}
	}
public:
    void solve(vector<vector<char>>& board) {
        for(size_t i = 0; i < board[0].size(); i++) {
			if(board[0][i] == 'O') { uncapture(board, 0, i); }
			if(board[board.size() - 1][i] == 'O') { uncapture(board, board.size() - 1, i); }
		}
		for(size_t i = 1; i < board.size() - 1; i++) {
			if(board[i][0] == 'O') { uncapture(board, i, 0); }
			if(board[i][board[0].size() - 1] == 'O') { uncapture(board, i, board[0].size() - 1); }
		}
		for(size_t r = 0; r < board.size(); r++) {
			for(size_t c = 0; c < board[0].size(); c++) {
				board[r][c] = board[r][c] == 'o' ? 'O' : 'X';
			}
		}
    }
};

/* ----- Testing ----- */
struct Testing {
	vector<vector<char>> board;
	vector<vector<char>> vecOut;
	static void print(const vector<vector<char>>& vec) {
		for(const auto& line : vec) {
			for(const auto& cell : line) {
				cout << cell;
			}
			cout << endl;
		}
	}
};

const int TCASE_SIZE = 2;

int main() {
	Testing t[TCASE_SIZE] = {
		{{
			 {'X', 'X', 'X', 'X'},
			 {'X', 'O', 'O', 'X'},
			 {'X', 'X', 'O', 'X'},
			 {'X', 'O', 'X', 'X'}
		},
		{
			 {'X', 'X', 'X', 'X'},
			 {'X', 'X', 'X', 'X'},
			 {'X', 'X', 'X', 'X'},
			 {'X', 'O', 'X', 'X'}
		}},
		{{{'X'}}, {{'X'}}}
	};

	Solution s;

	for(auto& tcase : t) {
		s.solve(tcase.board);
		if(tcase.vecOut != tcase.board) {
			cout << "FAIL\n\nwant" << endl;
			Testing::print(tcase.vecOut);
			cout << "\ngot" << endl;
			Testing::print(tcase.board);
			return 1;
		}
	}

	cout << "ok" << endl;
	return 0;
}
