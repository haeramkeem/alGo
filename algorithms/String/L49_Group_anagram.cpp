/**
 * Leetcode 49
 * 
 * Group Anagram
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/* ----- Solution ----- */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 2) { return {strs}; }
        map< string, vector<string> > mRes;
        vector<vector<string>> vecOut;
        for(const auto& word : strs) {
            string strS = word;
            sort(strS.begin(), strS.end());
            if(mRes.find(strS) == mRes.end()) {
                mRes[strS] = {word};
            } else {
                mRes[strS].push_back(word);
            }
        }
        for(const auto& it : mRes) {
            vecOut.push_back(mRes[it.first]);
        }
        return vecOut;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<string> vecInput;
    vector< vector<string> > vecOutput;
};

int main() {
    Testing t[3] = {
        Testing{
            {"eat","tea","tan","ate","nat","bat"},
            {{"bat"}, {"eat", "tea", "ate"}, {"tan", "nat"}},
        },
        Testing{
            {""},
            {{""}},
        },
        Testing{
            {"a"},
            {{"a"}},
        }
    };

    Solution s;

    for(auto tcase : t) {
        auto res = s.groupAnagrams(t->vecInput);
        if(t->vecOutput != res) {
            cout << "FAIL" << endl;
            
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}