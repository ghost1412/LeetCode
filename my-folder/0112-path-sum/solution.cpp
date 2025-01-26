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

    bool eval(TreeNode* root, int target, int curr) {
        if (root == NULL) return false;
        curr += root->val;
        if (root->left == NULL && root->right == NULL) return curr == target;
        return eval(root->left, target, curr) || eval(root->right, target, curr);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return eval(root, targetSum, 0);
    }
};
