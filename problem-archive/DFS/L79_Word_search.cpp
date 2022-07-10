/**
 * Leetcode 79) https://leetcode.com/problems/word-search/
 * 
 * Word Search
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
private:
    bool visit(vector<vector<char>>& board, string& word, int ridx, int cidx, int widx) {
        if(widx + 1 >= word.size()) { return true; }
        if(0 < ridx && board[ridx - 1][cidx] == word[widx + 1]) {
            char tmp = board[ridx][cidx];
            board[ridx][cidx] = '\0';
            if(visit(board, word, ridx - 1, cidx, widx + 1)) { return true; }
            board[ridx][cidx] = tmp;
        }
        if(cidx < board[0].size() - 1 && board[ridx][cidx + 1] == word[widx + 1]) {
            char tmp = board[ridx][cidx];
            board[ridx][cidx] = '\0';
            if(visit(board, word, ridx, cidx + 1, widx + 1)) { return true; }
            board[ridx][cidx] = tmp;
        }
        if(ridx < board.size() - 1 && board[ridx + 1][cidx] == word[widx + 1]) {
            char tmp = board[ridx][cidx];
            board[ridx][cidx] = '\0';
            if(visit(board, word, ridx + 1, cidx, widx + 1)) { return true; }
            board[ridx][cidx] = tmp;
        }
        if(0 < cidx && board[ridx][cidx - 1] == word[widx + 1]) {
            char tmp = board[ridx][cidx];
            board[ridx][cidx] = '\0';
            if(visit(board, word, ridx, cidx - 1, widx + 1)) { return true; }
            board[ridx][cidx] = tmp;
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int ridx = 0; ridx < board.size(); ridx++) {
            for(int cidx = 0; cidx < board[0].size(); cidx++) {
                if(board[ridx][cidx] == word[0]) {
                    if(visit(board, word, ridx, cidx, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<vector<char>> vecInput;
    string strInput;
    bool bOutput;
};

int main() {
    Testing t[4] = {
        Testing{{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCCED", true},
        Testing{{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "SEE", true},
        Testing{{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCB", false},
        Testing{{{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}}, "ABCESEEEFS", true},
    };

    Solution s;
    for(const auto tcase : t) {
        auto vec = tcase.vecInput;
        auto str = tcase.strInput;
        auto bl = s.exist(vec, str);
        if(tcase.bOutput != bl) {
            cout << "FAIL at " << str << " with " << boolalpha << bl << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}