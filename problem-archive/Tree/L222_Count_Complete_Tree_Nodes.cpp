/**
 * Leetcode 222) https://leetcode.com/problems/count-complete-tree-nodes/
 *
 * Count Complete Tree Nodes
 */

#include <iostream>
#include <queue>

using namespace std;

/* ----- Solution ----- */
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
    int countNodes(TreeNode* root) {
		if(!root) { return 0; }
		queue<TreeNode*> q;
		q.push(root);
		int nCnt = 0;
		while(!q.empty()) {
			auto h = q.front();
			q.pop();
			nCnt++;
			if(h->left) { q.push(h->left); }
			if(h->right) { q.push(h->right); }
		}
		return nCnt;
    }
};
