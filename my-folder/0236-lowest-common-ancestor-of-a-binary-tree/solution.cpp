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
    bool find(TreeNode* root, TreeNode* s){
        if(root == NULL) return false;
        else if(root == s) return true;
        else
            return(find(root->left, s)||find(root->right, s));
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(find(root->left, p) && find(root->left, q))
                root = root->left;
            else if(find(root->right, p) && find(root->right, q))
                root = root->right;
            else
                break;
        }
        return root;
    }
};
