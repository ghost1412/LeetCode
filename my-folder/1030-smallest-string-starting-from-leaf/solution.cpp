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
    string ans = "";
public:   
    void paths(TreeNode* root, string till){
        if(!root)
            return;
        if(root->left) paths(root->left, (char)(root->val+'a')+till);
        if(root->right) paths(root->right, (char)(root->val+'a')+till);
        if(!root->left && !root->right){
            till = (char)(root->val+'a')+till;
            if(ans.size() == 0)
                ans = till;
            else if(till < ans)
                ans = till;
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        paths(root, "");
        return ans;
    }
};
