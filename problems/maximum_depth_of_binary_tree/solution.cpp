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
    int get_depth(TreeNode* root, int n){
        if(root == NULL) return n;
        if(root->left == NULL && root->right == NULL) return n+1;
        return max(get_depth(root->right, n), get_depth(root->left, n)) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return (root == NULL)? 0:get_depth(root, 0);
    }
};