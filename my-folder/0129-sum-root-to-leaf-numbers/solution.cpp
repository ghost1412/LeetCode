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

    int sum(TreeNode* root, string sumTill) {
        if (root == NULL) return stoi(sumTill);
        sumTill = sumTill+to_string(root->val);
        if (root->left == NULL && root->right == NULL) return stoi(sumTill);
        int leftSum = (root->left != NULL) ? sum(root->left, sumTill) : 0;
        int rightSum = (root->right != NULL) ? sum(root->right, sumTill) : 0;
        return  leftSum+rightSum;
    }

    int sumNumbers(TreeNode* root) {
        return sum(root, "");
    }
};
