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
    TreeNode* prev = new TreeNode(INT_MIN), *first = NULL, *second = NULL;
    void recoverTree(TreeNode* root) {
        traverse(root);
        prev = new TreeNode(INT_MIN);
        swap(first->val, second->val);
    }

    void traverse(TreeNode* root) {
        if (root == NULL) return;

        traverse(root->left);

        if (first == NULL && prev->val > root->val) {
            first = prev;
        }

        if (first != NULL && prev->val > root->val) {
            second = root;
        }

        prev = root;
        traverse(root->right);
    }
};
