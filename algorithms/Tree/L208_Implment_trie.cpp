/**
 * Leetcode 208) https://leetcode.com/problems/implement-trie-prefix-tree/
 * 
 * Implement Trie (Prefix Tree)
 * 
 * ref: c-style array, new & delete(malloc & free), destructor
 */

#include <iostream>

using namespace std;

/* ----- Solution ----- */
class Trie {
private:
    Trie* children[26] = {NULL};
    bool isLastOfWord = false;
public:
    ~Trie() {
        for(int i = 0; i < 26; i++) {
            if(this->children[i]) { delete this->children[i]; }
        }
    }

    void insert(string word) {
        Trie* it = this;
        for(const char& ch : word) {
            if(!it->children[ch - 'a']) { it->children[ch - 'a'] = new Trie(); }
            it = it->children[ch - 'a'];
        }
        it->isLastOfWord = true;
    }
    
    bool search(string word) {
        Trie* it = this;
        for(const char& ch : word) {
            if(!it->children[ch - 'a']) { return false; }
            it = it->children[ch - 'a'];
        }
        return it->isLastOfWord;
    }
    
    bool startsWith(string prefix) {
        Trie* it = this;
        for(const char& ch : prefix) {
            if(!it->children[ch - 'a']) { return false; }
            it = it->children[ch - 'a'];
        }
        return true;
    }
};

/* ----- Testing ----- */
int main() {
    Trie trie;

    trie.insert("apple");
    if(!trie.search("apple")) { cout << "FAIL" << endl; return 1; }
    if(trie.search("app")) { cout << "FAIL" << endl; return 1; }
    if(!trie.startsWith("app")) { cout << "FAIL" << endl; return 1; }

    cout << "ok" << endl;
    return 0;
}