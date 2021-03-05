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
    bool isSameTree(TreeNode* p, TreeNode* q) {        
        stack<TreeNode*> a, b;
        if(p)
            a.push(p);
        if(q)
            b.push(q);
        while(!a.empty()&&!b.empty()){
            if(a.top()->val != b.top()->val)
                return 0;
            TreeNode* top = a.top();
            a.pop();
            TreeNode* top1 = b.top();
            b.pop();
            if(top->left && top1->left || (top->left == NULL && top1->left == NULL)){
                if(top->left != NULL){
                    if(top->left->val == top1->left->val){
                        a.push(top->left);
                        b.push(top1->left);           
                    }else
                        return 0;
                }
            }else
                return 0;
            if(top->right && top1->right|| (top->right == NULL && top1->right == NULL)){
                if(top->right != NULL){
                    if(top->right->val == top1->right->val){
                        a.push(top->right);
                        b.push(top1->right);           
                    }else
                        return 0;
                }
            }else
                return 0;        
        }
        if(a.size()!=b.size())
            return 0;
        return 1;
    }
};