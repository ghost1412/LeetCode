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
bool flag = 0;
public:   
    void paths(TreeNode* root, int till, int targetSum){
        if(!root)
            return;
        if(root->left) paths(root->left, till+root->val, targetSum);
        if(root->right) paths(root->right, till+root->val, targetSum);
        if(!root->left && !root->right){
            till += root->val;
            if(targetSum == till){
                flag = 1;
                return;
            }
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        paths(root, 0, targetSum);
        return flag;        
    }
};