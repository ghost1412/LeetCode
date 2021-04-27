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
    int checkNodes(TreeNode* root, int n){
        if(!root) return 0;
        return checkNodes(root->left, max(n, root->val)) + 
            checkNodes(root->right, max(n, root->val)) + (root->val >= n);
    }
    
    int goodNodes(TreeNode* root) {
        return checkNodes(root, INT_MIN);
    }
};