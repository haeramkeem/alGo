/**
 * Leetcode 721) https://leetcode.com/problems/accounts-merge/
 *
 * Accounts Merge
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/* ----- Solution ----- */
#define umap unordered_map

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        umap<string, vector<set<string>>> merged;
        
        bool found = false;
        for(const auto& account : accounts) {
            if(merged.count(account[0]) == 0) {
                merged[account[0]] = { set<string>(account.begin() + 1, account.end()) };
            } else {
                for(auto& s : merged[account[0]]) {
                    for(const auto& email : account) {
                        if(s.count(email) != 0) {
                            s.insert(account.begin() + 1, account.end());
                            found = true;
                            goto FOUND;
                        }
                    }
                }
                goto NOTFOUND;
                FOUND: continue;
                NOTFOUND:
                    merged[account[0]].push_back(set<string>(account.begin() + 1, account.end()));
            }
        }

        vector<vector<string>> res;
        for(auto it = merged.begin(); it != merged.end(); it++) {
            for(const auto& s : it->second) {
                vector<string> tmp = { it->first };
                tmp.reserve(s.size());
                tmp.insert(tmp.end(), s.begin(), s.end());
                res.push_back(tmp);
            }
        }
        return found ? accountsMerge(res) : res;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<vector<string>> inp, outp;
    Testing(vector<vector<string>> i, vector<vector<string>> o): inp(i), outp(o) {}
    
    const static int SIZE = 3;
    static void print(vector<vector<string>> arg) {
        cout << "{ ";
        for(const auto& acc : arg) {
            cout << "{ ";
            for(const auto& el : acc) {
                cout << el << ' ';
            }
            cout << "} ";
        }
        cout << "}\n";
    }
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({
            {"John","johnsmith@mail.com","john_newyork@mail.com"},
            {"John","johnsmith@mail.com","john00@mail.com"},
            {"Mary","mary@mail.com"},
            {"John","johnnybravo@mail.com"},
        },{
            {"John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"},
            {"John","johnnybravo@mail.com"},
            {"Mary","mary@mail.com"},
        }),
        Testing({
            {"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},
            {"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},
            {"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},
            {"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},
            {"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"},
        },{
            {"Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"},
            {"Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"},
            {"Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"},
            {"Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"},
            {"Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"},
        }),
        Testing({
            {"David","David0@m.co","David1@m.co"},
            {"David","David3@m.co","David4@m.co"},
            {"David","David4@m.co","David5@m.co"},
            {"David","David2@m.co","David3@m.co"},
            {"David","David1@m.co","David2@m.co"},
        }, {
            {"David","David0@m.co","David1@m.co","David2@m.co","David3@m.co","David4@m.co","David5@m.co"}
        }),
    };

    Solution s;
    for(auto& tcase : t) {
        auto res = s.accountsMerge(tcase.inp);
        if(res != tcase.outp) {
            cout << "FAIL\nwant: ";
            Testing::print(tcase.outp);
            cout << "got: ";
            Testing:: print(res);
            return 1;
        }
    }

    cout << "ok\n";
    return 0;
}
