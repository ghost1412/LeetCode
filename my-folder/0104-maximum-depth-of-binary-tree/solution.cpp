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

    int findMax(TreeNode* root, int maxD) {
        if (!root) return maxD;
        maxD++;
        return max(findMax(root->left, maxD), findMax(root->right, maxD));
    }

    int maxDepth(TreeNode* root) {
        return findMax(root, 0);
    }
};
