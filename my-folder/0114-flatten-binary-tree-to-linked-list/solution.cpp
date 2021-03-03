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
    void flatten(TreeNode* root) {
        if(root==NULL|| (root->left==NULL&&root->right==NULL)) return;
        TreeNode* node = root;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            node = s.top();
            s.pop();
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
            node->left = NULL; 
            root->right = node;
            root = root->right;
        }
    }
};
