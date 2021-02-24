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
    void trav(TreeNode* &node, int &curr){
        if(node == NULL) return;
        trav(node->right, curr);
        node->val += curr;
        curr = node->val;
        trav(node->left, curr);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return root;
        int curr = 0;
        trav(root, curr);
        return root;
    }
};