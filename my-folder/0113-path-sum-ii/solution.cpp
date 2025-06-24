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

    void calculatePath(TreeNode* root, int targetSum, int sumTill, vector<vector<int>>& res, vector<int>till) {
        if (root==NULL) return;
        if (root->left!=NULL) {
            vector<int> newTill = till;
            newTill.push_back(root->left->val);
            calculatePath(root->left, targetSum, sumTill+root->val, res, newTill);
        }

        if (root->right!=NULL) {
            vector<int> newTill = till;
            newTill.push_back(root->right->val);
            calculatePath(root->right, targetSum, sumTill+root->val, res, newTill);
        }
        if (root->left==NULL && root->right==NULL) {
            sumTill+=root->val;
            if (sumTill==targetSum) {
                res.push_back(till);
            }
        }

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> res;
        if (!root) return res;
        vector<int>till;
        till.push_back(root->val);
        calculatePath(root, targetSum, 0, res, till);
        return res;
    }
};
