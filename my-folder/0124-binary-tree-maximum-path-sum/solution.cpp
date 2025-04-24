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
    int maxPathSum(TreeNode* root) {
        int maxSUM = INT_MIN;
        maxSumD(root, maxSUM);
        return maxSUM;
    }

    int maxSumD(TreeNode*root, int &maxSum) {
        if (root == NULL) return 0;
        int left = max(0, maxSumD(root->left, maxSum));
        int right = max(0, maxSumD(root->right, maxSum));
        // cout<<left<<" "<<right<<" "<<((root->val>0 ? root->val:0) + (left>0?left:0) + (right>0?right:0))<<" ";
        maxSum = max(maxSum, left+right+root->val);
        return max(left, right)+root->val;
    }
};
