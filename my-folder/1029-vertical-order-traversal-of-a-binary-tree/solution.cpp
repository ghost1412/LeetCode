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

    void traverse(map<int, vector<pair<int,int>>>& mp, TreeNode* root, int col, int row) {
        if (root != NULL) {

            mp[col].push_back({row, root->val});
            
            traverse(mp, root->left, col-1, row+1);
            traverse(mp, root->right, col+1, row+1);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp;
        traverse(mp, root, 0, 0);
        vector<vector<int>> result;

        for (auto& [key, vec] : mp) { 
            sort(vec.begin(), vec.end()); 
            vector<int> sortedValues;
            for (auto& [row, val] : vec) {
                sortedValues.push_back(val);
            }
            result.push_back(sortedValues);
        }
        return result;
    }
};
