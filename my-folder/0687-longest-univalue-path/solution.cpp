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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int maxPath = 0;
        dfs(root, maxPath);
        return maxPath;
    }

    int dfs(TreeNode* root, int & maxPath) {
        if (!root) return 0;
        
        int left = dfs(root->left, maxPath);
        int right = dfs(root->right, maxPath);
        int leftPath =0, rightPath =0;

        if (root->left && root->left->val == root->val) {
            leftPath = left+1;
        }

        if (root->right && root->right->val == root->val) {
            rightPath = right+1;
        }

        maxPath = max(maxPath, leftPath+rightPath);
        return max(leftPath, rightPath);
    }
};
