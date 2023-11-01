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

    int postOrder(TreeNode* root, int &transfer) {
        if (root == NULL) return 0;
        int left = postOrder(root->left, transfer);
        int right = postOrder(root->right, transfer);
        transfer += abs(left) +  abs(right);
        return root->val + left + right - 1;
    }

    int distributeCoins(TreeNode* root) {

        int transfer = 0;
        postOrder(root, transfer);
        return transfer;
    }
};
