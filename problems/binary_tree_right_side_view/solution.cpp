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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode* > dq;
        dq.push_back(root);
        dq.push_back(nullptr);
        vector<int> result;
        if(!root) return result;
        while(!dq.empty()){
            bool pushed = false;
            while(dq.front()){                

                auto top = dq.front();
                dq.pop_front();
                if(!pushed){//cout<<top->val;
                    result.push_back(top->val);
                    pushed = true;
                }
                if(top->right){
                    dq.push_back(top->right);
                }
                if(top->left){
                    dq.push_back(top->left);
                }
            }        
         //  cout<<dq.size();
          //  cout<<endl;
            dq.pop_front();
            if(!dq.empty())
                dq.push_back(nullptr);  
        }
        return result;
    }
};