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
    void sumLevel(TreeNode* root, int level, vector<double>& sum, vector<double>& ele) {
        if (root == NULL) {
            return;
        }
       // cout<<level<<" "<<sum.size();
        if (level >= sum.size()) {
            cout<<"here";
            sum.push_back(root->val);
            ele.push_back(1);
        } else {
            sum[level] += root->val;
            ele[level] += 1;
        }
        sumLevel(root->left, level+1, sum, ele);
        sumLevel(root->right, level+1, sum, ele);
        return;
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum;
        vector<double> ele;
        sumLevel(root, 0, sum, ele);
        cout<<sum.size();
        for (int i=0; i<sum.size(); i++) {
            sum[i] /= ele[i];
        }
        return sum;
    }
};
