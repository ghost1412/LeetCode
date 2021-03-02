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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int hl = 1, hr = 1;
        auto hleft = root->left;
        auto hright = root->right;
        while(hleft!=NULL){
            hl++;
            hleft = hleft->left;
        }
        while(hright!=NULL){
            hr++;
            hright = hright->right;
        }    
      //  cout<<hl<<hr<<" ";
        if(hl == hr)
            return pow(2, hr) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};