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

    void traverse(unordered_map<int, vector<int>>& m, TreeNode* root) {
        if (root == NULL) return;

        if (root->left) {
            m[root->left->val].push_back(root->val);
            m[root->val].push_back(root->left->val);
        }

        if (root->right) {
            m[root->right->val].push_back(root->val);
            m[root->val].push_back(root->right->val);
        }
        traverse(m, root->left);
        traverse(m, root->right);
        return;
    }
 
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> mp;
        traverse(mp, root);
        queue<int> s;
        s.push(start);
        unordered_map<int, bool> visited;
        visited[start] = true;
         int ans = -1;
        while (!s.empty()) {
            ans += 1;

            int size = s.size();
            for (int i=0; i<size; i++){
                int frontNode = s.front();
                s.pop();
                for (int node : mp[frontNode]) {
                    if (!visited[node]) {
                        visited[node] = true;
                        s.push(node);
                    }
                }
            }

        }
        return ans;
    }
};
