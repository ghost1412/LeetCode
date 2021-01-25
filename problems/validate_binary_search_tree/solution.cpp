/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isValidBST(TreeNode* node,long mn=-10000000000,long mx=10000000000) {
        if(!node) return true;
        long val = (int)node->val;
        return val>mn && val<mx && isValidBST(node->left, mn, min(mx, val)) && isValidBST(node->right, max(mn, val), mx);     
    }
};