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
    void flatten(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* prev = NULL;

        while (!s.empty()) {
            auto top = s.top();

            s.pop();
            if (top->right) s.push(top->right);
            if (top->left) s.push(top->left);
            if (prev) {
                prev->right = top;
                prev->left = NULL;
            }

            prev = top;
        }
    }


};
