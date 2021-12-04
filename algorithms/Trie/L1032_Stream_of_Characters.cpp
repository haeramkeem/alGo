/**
 * Leetcode 1032) https://leetcode.com/problems/stream-of-characters/
 *
 * Stream of Characters
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class StreamChecker {
    struct TrieNode {
        TrieNode* next[26];
        bool isEnd;

        TrieNode() {
            for(auto& nextNode : next) {
                nextNode = nullptr;
            }
            isEnd = false;
        }

        ~TrieNode() {
            for(auto& nextNode : next) {
                if(nextNode != nullptr) {
                    delete nextNode;
                }
            }
        }
    };

    TrieNode* root;
    string stream;
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        stream = "";
        stream.reserve(40000);

        for(const auto& word : words) {
            auto it = root;
            for(auto rit = word.rbegin(); rit < word.rend(); rit++) {
                if(!it->next[*rit - 'a']) {
                    it->next[*rit - 'a'] = new TrieNode();
                }
                it = it->next[*rit - 'a'];
            }
            it->isEnd = true;
        }
    }

    bool query(char letter) {
        stream += letter;

        auto it = root;
        for(auto rit = stream.rbegin(); rit < stream.rend(); rit++) {
            if(!it->next[*rit - 'a']) {
                return false;
            } else {
                it = it->next[*rit - 'a'];
                if(it->isEnd) {
                    return true;
                }
            }
        }

        return false;
    }

    ~StreamChecker() {
        delete root;
    }
};

/* ----- Solution ----- */
struct Testing {
    vector<string> words;
    vector<pair<char, bool>> cases;
};

int main() {
    Testing t{
        {"cd","f","kl"},
        {
            make_pair('a', false),
            make_pair('b', false),
            make_pair('c', false),
            make_pair('d', true),
            make_pair('e', false),
            make_pair('f', true),
            make_pair('g', false),
            make_pair('h', false),
            make_pair('i', false),
            make_pair('j', false),
            make_pair('k', false),
            make_pair('l', true),
        }
    };

    StreamChecker sc(t.words);

    for(auto& tcase : t.cases) {
        if(tcase.second != sc.query(tcase.first)) {
            cout << "FAIL: at '" << tcase.first << "'\n";
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}
