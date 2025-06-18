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
    int kthSmallest(TreeNode* root, int k) {
        int ans=root->val;
        findKthSmallest(root, k, ans);
        return ans;
    }

    void findKthSmallest(TreeNode* root, int& k, int &ans) {
        if (root==NULL || k==0) return;

        findKthSmallest(root->left, k, ans);
        k--;
        if (k==0) ans = root->val;
        findKthSmallest(root->right, k, ans);


    }
};
