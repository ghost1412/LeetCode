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
    void paths(TreeNode* root, string till, vector<string> &ans){
        if(root->left){
            string val = till+"->"+to_string(root->left->val);
            if(root->left->left == NULL && root->left->right == NULL)
                ans.push_back(val);
            paths(root->left,val, ans);
        }
        if(root->right){
            string val = till+"->"+to_string(root->right->val);
            if(root->right->left == NULL && root->right->right == NULL)                       ans.push_back(val);            
            paths(root->right,val, ans)  ;      
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;        
        if(root == NULL)
            return ans;
        string till = to_string(root->val);
        if(root->left == NULL && root->right == NULL)
            ans.push_back(till);
        paths(root, till, ans);
        return ans;
    }
};
