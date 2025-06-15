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
    int sumNumbers(TreeNode* root) {
        if (root==NULL) return 0;
        if (root->left ==NULL && root->right == NULL)return root->val;
        int sum=0;
        int parent = root->val;
        computeSum(root->left, parent, sum);
        computeSum(root->right, parent, sum);
        return sum;
    }

    void computeSum(TreeNode* root, int parent, int& sum) {
        if (root == NULL) return;

        if (root->left==NULL && root->right==NULL) {
            sum += (parent*10 + root->val);
            return;
        }

        parent = parent*10 + root->val;
        computeSum(root->left, parent, sum);
        computeSum(root->right, parent, sum);
    }
};
