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
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    void sumLeaf(TreeNode* root, int height, int depth, int* sum){
        height++;
        if(root){
            if(height == depth){
                *sum += root->val;
            }else{
                if(root->left){
                    sumLeaf(root->left, height, depth, sum);
                }
                if(root->right){
                    sumLeaf(root->right, height, depth, sum);
                }
            }
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int depth = maxDepth(root);
        int sum = 0, height = 0;
        sumLeaf(root, height, depth, &sum);
        return sum;
    }
};