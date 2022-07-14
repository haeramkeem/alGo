/**
 * Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal
 * @see https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define v_iter vector<int>::iterator
#define umap unordered_map
class Solution {
    // Cache for finding pointer more quickly
    umap<int, v_iter> inMap;

    TreeNode* buildSubTree(v_iter preBegin, v_iter preEnd, v_iter inBegin, v_iter inEnd) {
        // Root is guaranteed to bw not-null
        TreeNode* root = new TreeNode(*preBegin);

        // In-order vector is structured as
        // { ...leftInorder, root, ...rightInorder }
        // And preBegin is always root by the definition for the pre-order traversal
        v_iter inMid = inMap[*preBegin];

        // Pre-order vector is structured as
        // { root, ...leftPreorder, ...rightPreorder }
        // Thus the starting point of the `...rightPreorder` can be calculated with the formula below
        // As the number of elements for left subtree can be calculated with (inMid - inBegin)
        v_iter preMid = (inMid - inBegin) + preBegin + 1;

        // If `preBegin + 1` is equal to `preMid`
        // or `inBegin` is equal to `inMid`, it means left subtree is null
        if (preBegin + 1 != preMid && inBegin != inMid) {
            root->left = buildSubTree(preBegin + 1, preMid, inBegin, inMid);
        }

        // If `preMid` is equal to `preEnd`
        // or `inMid + 1` is equal to `inEnd`, it means right subtree is null
        if (preMid != preEnd && inMid + 1 != inEnd) {
            root->right = buildSubTree(preMid, preEnd, inMid + 1, inEnd);
        }

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Make cache
        for(v_iter it = inorder.begin(); it != inorder.end(); it++) {
            inMap[*it] = it;
        }

        return buildSubTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};

int main() {
    return 0;
}
