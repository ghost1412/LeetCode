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
        if(root->left) paths(root->left, till+to_string(root->val));
        if(root->right) paths(root->right, till+to_string(root->val));
        if(!root->left && !root->right){
            till += to_string(root->val);
            if(ans.size() == 0)
                ans = till;
            else{
                ans = to_string(stoi(ans)+stoi(till));
            }
        }
    }

    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        paths(root, "");
        return stoi(ans);
    }
};