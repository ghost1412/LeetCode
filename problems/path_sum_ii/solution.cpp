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
vector<vector<int>> ans;
public:   
    void paths(TreeNode* root, int till, int targetSum, vector<int> temp){
        if(!root)
            return;
        if(root->left){
            vector<int> temp1 = temp;
            temp1.push_back(root->left->val);
            paths(root->left, till+root->val, targetSum, temp1);
        }
        if(root->right){
            vector<int> temp1 = temp;
            temp1.push_back(root->right->val);            
            paths(root->right, till+root->val, targetSum, temp1);
        } 
        if(!root->left && !root->right){
            till += root->val;
            if(targetSum == till){
                ans.push_back(temp);
            }
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        vector<int> temp;
        temp.push_back(root->val);
        paths(root, 0, targetSum, temp);
        return ans;         
    }
};