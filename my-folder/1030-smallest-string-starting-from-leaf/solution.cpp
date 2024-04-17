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
    string findSmallest(TreeNode* root, string currPath, string & currentShortest) {
        if (!root) currentShortest;
        char currentNode =  (char)(root->val+'a');
        if (root -> left) findSmallest(root->left, currentNode+currPath, currentShortest);
        if (root -> right) findSmallest(root->right, currentNode+currPath, currentShortest);

        if (!root->left && !root->right) {
            currPath = currentNode + currPath;
            if (!currentShortest.size()) {
                currentShortest = currPath;
            } else if (currPath < currentShortest) {
                currentShortest = currPath;
            }
        }
        return currentShortest;

    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        if (!root) return ans;
        return findSmallest(root, "", ans);
    }
};
