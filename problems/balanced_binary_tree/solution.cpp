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
    
    int maxDepth(TreeNode* r){ 
        if(r==NULL) return -1;

        return (max( maxDepth(r->left), maxDepth(r->right) ) + 1 ); 
    }
   
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return 1;
        if(isBalanced(root->left) && isBalanced(root->right)){
            return(abs(maxDepth(root->left) - maxDepth(root->right)) <=1 );
        }else
        return 0;
    }
};