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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;

        TreeNode* root = build(preorder, inorder, 0, preorder.size()-1, 0 , inorder.size()-1, mp);
        return root;
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> & mp) {
        if (preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int index = mp[preorder[preStart]];
        int inIndex = index - inStart;
        root->left = build(preorder, inorder, preStart+1, preStart+inIndex, inStart, index-1, mp);
        root->right = build(preorder, inorder, preStart+inIndex+1, preEnd, index+1, inEnd, mp);
        return root;
    }
};
