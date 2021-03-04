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

map<TreeNode*,int> mp;
    
public:
    // void genGraph(TreeNode* root, vector<int>&dp, unordered_map<int, vector<int>>& mp, int& index){
    //     if(root == NULL) return;
    //   //  dp.push_back(root->val);
    //     int temp = index;
    //     if(root->left){
    //         dp.push_back(root->left->val);
    //         index++;
    //         mp[temp].push_back(index);            
    //     }
    //     if(root->right){
    //         dp.push_back(root->right->val);
    //         index++;
    //         mp[temp].push_back(index); 
    //     }
    //     if(root->left){
    //         genGraph(root->left, dp, mp, index);
    //     }
    //     if(root->right){
    //         genGraph(root->right, dp, mp, index);
    //     }
    // }
    
    int rob(TreeNode* root) {
        // vector<int> val;
        // val.push_back(root->val);
        // unordered_map<int, vector<int>> mp;
        // int index = 0;
        // genGraph(root, val, mp, index);
        // int n = mp.size();
        // vector<int> dp(n, 0);
        // dp[0] = val[0];
        // int tempSum = 0;
        // for(int i=0; i<mp[0].size(); i++)
        //     tempSum += val[mp[0][i]];
        // dp[1] = max(val[0], tempSum);
        // for(int i=2; i<mp.size(); i++){
        //     //cout<<i;
        //     tempSum = 0;
        //     for(int j=0; j<mp[i].size(); j++)
        //         tempSum += val[mp[i][j]];
        //     cout<<mp[i].size()<<" ";
        //     dp[i] = max(dp[i-1], dp[i-2]+tempSum);
        // }
        // return dp[n-1];
        if(mp.find(root)!=mp.end()) return mp[root];
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        int tak = root->val;
        if(root->left) tak += rob(root->left->left) + rob(root->left->right);
        if(root->right) tak += rob(root->right->left) + rob(root->right->right);
        int not_tak = rob(root->left) + rob(root->right);
        mp[root] = max(tak, not_tak);     
        return mp[root];
    }
};
