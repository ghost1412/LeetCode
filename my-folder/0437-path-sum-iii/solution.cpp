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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1;
        return dfs(root, targetSum, 0, mp);
    }

    int dfs(TreeNode* root, int targetSum, long long currSum, unordered_map<long long, int>& mp) {
        if (!root) return 0;

        currSum += root->val;

        int numPath = mp[currSum-targetSum];

        mp[currSum]++;

        numPath += dfs(root->left, targetSum, currSum, mp);
        numPath += dfs(root->right, targetSum, currSum, mp);
        mp[currSum]--;
        return numPath;

    }
};
