/**
 * Leetcode 1008) https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
 * 
 * Construct Binary Search Tree from Preorder Traversal
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* ----- Domain ----- */
// Replacement for NULL
const int INULL = (int)NULL;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        if(this->left) { delete this->left; }
        if(this->right) { delete this->right; }
    }
    vector<int> toVector() {
        queue<TreeNode*> q;
        vector<int> res;
        q.push(this);
        while(!q.empty()) {
            auto h = q.front();
            q.pop();
            if(h != nullptr) {
                res.push_back(h->val);
                if(h->left || h->right) {
                    q.push(h->left);
                    q.push(h->right);
                }
            } else {
                res.push_back(INULL);
            }
        }
        return res;
    }
};

/* ----- Solution ----- */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(auto pit = preorder.begin() + 1; pit < preorder.end(); pit++) {
            TreeNode* it = root;
            while(true) {
                if(*pit < it->val) {
                    if(it->left) {
                        it = it->left;
                    } else {
                        it->left = new TreeNode(*pit);
                        break;
                    }
                } else if(it->val < *pit) {
                    if(it->right) {
                        it = it->right;
                    } else {
                        it->right = new TreeNode(*pit);
                        break;
                    }
                }
            }
        }
        return root;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<int> preorder;
    vector<int> output;
};

const int TCASE_SIZE = 2;

void printV(vector<int> arg) {
    cout << "{ ";
    for(const auto& el : arg) {
        cout << el << ' ';
    }
    cout << '}' << endl;
}

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{{8, 5, 1, 7, 10, 12}, {8, 5, 10, 1, 7, INULL, 12}},
        Testing{{1, 3}, {1, INULL, 3}},
    };

    Solution s;
    for(const auto& tcase : t) {
        auto inp = tcase.preorder;
        auto res = s.bstFromPreorder(inp);
        if(tcase.output != res->toVector()) {
            cout << "FAIL\nwant: ";
            printV(tcase.output);
            cout << "got: ";
            printV(res->toVector());
            delete res;
            return 1;
        }
        delete res;
    }

    cout << "ok" << endl;
    return 0;
}