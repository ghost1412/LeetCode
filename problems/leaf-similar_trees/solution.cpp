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
    void firstTree(TreeNode* root, vector<int>& s){
        if(root->left == NULL && root->right == NULL)
            s.push_back(root->val);
        if(root->left)
            firstTree(root->left, s);
        if(root->right)
            firstTree(root->right, s);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        firstTree(root1, leaf1);
        firstTree(root2, leaf2);
        return leaf1==leaf2;
    }
};