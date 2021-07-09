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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        int l = 0;
        bool flip = 0;
        while(!q.empty()){
            int s = q.size();
            vector<int> v;
            for(int i=0; i<s; i++){
                TreeNode* t = q.front();
                v.push_back(t->val);
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            if(flip) reverse(v.begin(), v.end());
            res.push_back(v);
            if(flip) flip = 0;
            else flip = 1;
        }
        return res;       
    }
};
