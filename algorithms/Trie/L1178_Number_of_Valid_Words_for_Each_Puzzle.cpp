/**
 * Leetcode 1178) https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
 *
 * Number of Valid Words for Each Puzzle
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

/* ----- Solution ----- */
struct Trie {
    char ch; // Node value
    int endNum; // Number of words that ends here
    array<Trie*, 26> next; // Next nodes

    Trie(const char& cc) {
        this->ch = cc;
        this->endNum = 0;
        this->next = {};
    }

    int find(string& str) {
        char fch = str[0];
        sort(str.begin(), str.end());
        bool found = false;
        int cnt = 0;
        findImpl(str, fch, this, 0, found, cnt);
        return cnt;
    }

    // Always maintain all words are sorted and do not contains duplicated letter
    void insert(const string& str /* Assume that a word inserted is sorted by ascending order */) {
        Trie* it = this;
        for(const auto& ch : str) {
            if(it->ch == ch) { continue; } // prevent duplicate letter
            if(!it->next[ch - 'a']) { it->next[ch - 'a'] = new Trie(ch); }
            it = it->next[ch - 'a'];
        }
        it->endNum++;
    }
    
    ~Trie() {
        for(const auto& el : next) {
            if(el) {
                delete el;
            }
        }
    }
private:
    static void findImpl(const string& str, const char& fch, const Trie* cur, const int& pos, bool& found, int& acc) {
        if(cur->ch == fch) { found = true; } // If current value is a first letter of puzzle, change found flag to true
        for(size_t i = pos; i < str.size(); i++) {
            if(cur->next[str[i] - 'a']) {
                findImpl(str, fch, cur->next[str[i] - 'a'], pos + 1, found, acc);
            }
        }
        if(cur->endNum > 0 && found) { acc += cur->endNum; } // if found flag is on and word which ends here exists
        if(cur->ch == fch) { found = false; } // revert changed flag
    }
};

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        Trie root('\n');
        vector<int> res;
        res.reserve(puzzles.size());
        // Make Trie
        for(auto& word : words) {
            sort(word.begin(), word.end());
            root.insert(word);
        }
        // Count valid word by with puzzle
        for(auto& puzz : puzzles) {
            res.push_back(root.find(puzz));
        }
        return res;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<string> words;
    vector<string> puzzles;
    vector<int> outp;
};

const int TCASE_SIZE = 2;

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{
            {"aaaa","asas","able","ability","actt","actor","access"},
            {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"},
            {1,1,3,2,4,0},
        },
        Testing{
            {"apple","pleas","please"},
            {"aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"},
            {0,1,3,2,0},
        },
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.findNumOfValidWords(tcase.words, tcase.puzzles);
        if(res != tcase.outp) {
            cout << "FAIL: want {";
            for(const auto& el : tcase.outp) {
                cout << el << ' ';
            }
            cout << "} got {";
            for(const auto& el : res) {
                cout << el << ' ';
            }
            cout << "}\n";
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
