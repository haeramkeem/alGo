/**
 * Leetcode 212) https://leetcode.com/problems/word-search-ii/
 * 
 * Word Search 2
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/* ----- Solution ----- */
struct Trie {
    char ch = '\0';
    bool isEnd = false;
    Trie* parent = nullptr;
    Trie* children[26] = {nullptr};
    void insert(const string& word) {
        Trie* it = this;
        for(const char& ch : word) {
            if(!it->children[ch - 'a']) { it->children[ch - 'a'] = new Trie(); }
            it->children[ch - 'a']->parent = it;
            it->children[ch - 'a']->ch = ch;
            it = it->children[ch - 'a'];
        }
        it->isEnd = true;
    }
    string toString() {
        Trie* it = this;
        char cstr[11];
        int idx = 0;
        while(it) { cstr[idx] = it->ch; it = it->parent; idx++; }
        cstr[idx] = '\0';
        string str = string(cstr);
        reverse(str.begin(), str.end());
        return str;
    }
    Trie* findChild(char& ch) {
        return ch == '\0' ? nullptr : this->children[ch - 'a'];
    }
    ~Trie() {
        for(const auto& child : this->children) {
            if(child) { delete child; }
        }
    }
};

class Solution {
    vector<vector<char>> board;
    set<string> setAns;
    Trie* root;

    void visit(int nRow, int nCol, Trie* cur) {
        if(cur->isEnd) { setAns.insert(cur->toString()); }
        char chTemp = board[nRow][nCol];
        board[nRow][nCol] = '\0';
        string strTemp = "";
        Trie* trTemp = nullptr;
        if(nRow - 1 >= 0 && (trTemp = cur->findChild(board[nRow - 1][nCol]))) {
            visit(nRow - 1, nCol, trTemp);
        }
        if(nCol + 1 < board[0].size() && (trTemp = cur->findChild(board[nRow][nCol + 1]))) {
            visit(nRow, nCol + 1, trTemp);
        }
        if(nRow + 1 < board.size() && (trTemp = cur->findChild(board[nRow + 1][nCol]))) {
            visit(nRow + 1, nCol, trTemp);
        }
        if(nCol - 1 >= 0 && (trTemp = cur->findChild(board[nRow][nCol - 1]))) {
            visit(nRow, nCol - 1, trTemp);
        }
        board[nRow][nCol] = chTemp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = board;
        this->root = new Trie();
        this->setAns.clear();
        for(const auto& word : words) { this->root->insert(word); }
        string strTemp = "";
        for(int nRow = 0; nRow < board.size(); nRow++) {
            for(int nCol = 0; nCol < board[0].size(); nCol++) {
                if(root->findChild(board[nRow][nCol])) {
                    visit(nRow, nCol, root->findChild(board[nRow][nCol]));
                }
            }
        }
        delete this->root;
        vector<string> vecAns(setAns.begin(), setAns.end());
        return vecAns;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<vector<char>> vecBoard;
    vector<string> vecWords;
    vector<string> vecOut;
};

const int TCASE_SIZE = 4;

void print(vector<string> arg) {
    cout << "{ ";
    for(const auto& str : arg) {
        cout << str << ' ';
    }
    cout << '}' << endl;
}

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{
            {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}},
            {"oath","pea","eat","rain"},
            {"eat","oath"},
        },
        Testing{
            {{'o','a','b','n'},{'o','t','a','e'},{'a','h','k','r'},{'a','f','l','v'}},
            {"oa","oaa"},
            {"oa","oaa"},
        },
        Testing{
            {{'a','b'},{'c','d'}},
            {"abcb"},
            {}
        },
        Testing{
            {{'a','a'}},
            {"aa"},
            {"aa"},
        }
    };

    Solution s;
    for(int i = 0; i < TCASE_SIZE; i++) {
        auto board = t[i].vecBoard;
        auto words = t[i].vecWords;
        auto res = s.findWords(board, words);
        if(res != t[i].vecOut) {
            cout << "FAIL" << endl << "want: ";
            print(t[i].vecOut);
            cout << "got: ";
            print(res);
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}