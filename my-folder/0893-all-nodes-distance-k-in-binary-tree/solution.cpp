/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void CreateGraph(unordered_map<int, vector<int>>& m, TreeNode* root) {
        if (root == nullptr) return;

        if (root->left) {
            m[root->left->val].push_back(root->val);
            m[root->val].push_back(root->left->val);
        }

        if (root->right) {
            m[root->right->val].push_back(root->val);
            m[root->val].push_back(root->right->val);
        }
        CreateGraph(m, root->left);
        CreateGraph(m, root->right);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph;
        CreateGraph(graph, root);

        queue<int> q;

        vector<int> distK;

        q.push(target->val);
        unordered_map<int, bool> visited;
        visited[target->val] = true;
        int currentDist = 0;
        while (!q.empty()) {

            int size = q.size();
            if (currentDist == k) {
                for (int i=0; i<size; i++) {
                    int frontNode = q.front();
                    q.pop();
                    distK.push_back(frontNode);
                }
                return distK;
            }
            for (int i=0; i<size; i++) {
                int frontNode = q.front();
                q.pop();
                for (int node : graph[frontNode]) {
                    if (!visited[node]) {
                        q.push(node);
                        visited[node] = true;
                    }
                }
            }
            currentDist += 1;
        } 
        
        return distK;
    }
};
