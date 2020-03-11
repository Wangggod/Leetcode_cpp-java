// Source: https://leetcode.com/problems/invert-binary-tree/
// Author: Wangggod
// Date: 2020.3.11

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        auto q = queue<TreeNode*>();
        q.push(root);
        while (!q.empty()) {
            auto n = q.front(); q.pop();
            swap(n->left,n->right);
            if (n->left != nullptr) {
                q.push(n->left);
            }
            if (n->right != nullptr) {
                q.push(n->right);
            }
        }
        return root;
    }
};
