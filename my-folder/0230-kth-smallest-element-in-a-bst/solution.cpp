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
    void traverse(TreeNode* root, int &counter, int &k, int &ans) {
        if (root == NULL) return;
        traverse(root->left, counter, k, ans);
        counter++;
        if (counter == k) {
            ans = root->val;
            return;
        }
        traverse(root->right, counter, k, ans);
        return;

    }

    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int ans = -1;
        traverse(root, counter, k, ans);
        return ans;
    }
};
