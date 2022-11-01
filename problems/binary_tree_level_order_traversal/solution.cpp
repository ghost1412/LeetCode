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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> levelNodes;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int queueSize = q.size();
            vector<int> currLevelNodes;
            for (int i=0; i < queueSize; i++) {
                TreeNode* queueTop = q.front();
                currLevelNodes.push_back(queueTop->val);
                q.pop();
                if (queueTop->left) {
                    q.push(queueTop->left);
                }
                if (queueTop->right) {
                    q.push(queueTop->right);
                }
            }
            levelNodes.push_back(currLevelNodes);
        }
        return levelNodes;
    }
};