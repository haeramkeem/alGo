/**
 * Leetcode 102) Binary Tree Level Order Traversal
 * @see https://leetcode.com/problems/binary-tree-level-order-traversal/
 */
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

#define marshal(l, v) (10000 * (l) + (v) + 2000)
#define unmarshal_lv(v) ((v) / 10000)
#define unmarshal_val(v) ((v) % 10000 - 2000)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode*> q;
        root->val = marshal(0, root->val);
        q.push(root);

        vector<vector<int>> result;
        while (!q.empty()) {
            auto head = q.front();
            int level = unmarshal_lv(head->val);
            int val = unmarshal_val(head->val);

            if (result.size() - 1 == level) {
                result[level].push_back(val);
            } else {
                result.push_back({val});
            }

            if (head->left) {
                head->left->val = marshal(level + 1, head->left->val);
                q.push(head->left);
            }

            if (head->right) {
                head->right->val = marshal(level + 1, head->right->val);
                q.push(head->right);
            }

            q.pop();
        }

        return result;
    }
};

int main() {
    return 0;
}
