/**
 * Leetcode 450) https://leetcode.com/problems/delete-node-in-a-bst/
 *
 * Delete Node in a BST
 */

#include <iostream>

using namespace std;

/* ----- Domain ----- */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* ----- Solution ----- */
class Solution {
    TreeNode* doDelete(TreeNode* tar) {
        if(tar->right && tar->left) {
            auto suc = tar->right;
            while(suc->left) {
                suc = suc->left;
            }
            tar->val = suc->val;
            tar->right = deleteNode(tar->right, tar->val);
        } else if(tar->right) {
            return tar->right;
        } else if(tar->left) {
            return tar->left;
        } else {
            return nullptr;
        }
        return tar;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return nullptr;
        } else if(root->val == key) {
            return doDelete(root);
        }

        auto par = root;
        while(par) {
            if(par->left) {
                if(par->left->val == key) {
                    par->left = doDelete(par->left);
                    break;
                } else if(par->val > key) {
                    par = par->left;
                    continue;
                }
            }
            if(par->right) {
                if(par->right->val == key) {
                    par->right = doDelete(par->right);
                    break;
                } else if(par->val < key) {
                    par = par->right;
                    continue;
                }
            }
            break;
        }
        return root;
    }
};
