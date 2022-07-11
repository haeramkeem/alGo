#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // Null check
        if (!root) {
            return {};
        }

        queue<TreeNode*> q;
        // Set newVal := 1000 * level + oldVal
        root->val = 1000 * 0 + (root->val + 200);
        q.push(root);

        vector<int> res;
        while(!q.empty()) {
            auto head = q.front();
            int level = head->val / 1000;
            int val = head->val % 1000 - 200;

            if (res.size() - 1 == level) {
                // Overwrite right-end element
                res[level] = val;
            } else {
                // Init right-end element
                res.push_back(val);
            }

            if (head->left) {
                auto left = head->left;
                left->val = 1000 * (level + 1) + (left->val + 200);
                q.push(left);
            }

            if (head->right) {
                auto right = head->right;
                right->val = 1000 * (level + 1) + (right->val + 200);
                q.push(right);
            }

            q.pop();
        }

        return res;
    }
};
