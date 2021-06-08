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
    string get_letseq(TreeNode* root){
        if(root == NULL) return "";
        if(root->left == NULL && root->right == NULL) return to_string(root->val);
        string left = "", right = "";
        if(root->left != NULL)
            left = get_letseq(root->left);
        if(root->right != NULL)
            right = get_letseq(root->right);
        if(left!="" && right!="")
            return left+','+right;
        return left+right;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return get_letseq(root1) == get_letseq(root2);
    }
};