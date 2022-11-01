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
    int findHeight(TreeNode* root, int currentHeight) {
        if (!root) return currentHeight;
        currentHeight += 1;
        return max(findHeight(root->left, currentHeight), findHeight(root->right, currentHeight));
    }
    
    int maxDepth(TreeNode* root) {
        return findHeight(root, 0);
    }
};
