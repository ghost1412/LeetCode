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
    int maxDepth(TreeNode* root) {
        deque<TreeNode* > dq;
        int depth = 1;
        if(root){
            dq.push_back(root);
            dq.push_back(nullptr);   
        }else
            return 0;
        while(!dq.empty()){
            while(dq.front()){
                auto top = dq.front();
                dq.pop_front();
              //  depth++;
             //   if(top->right == NULL && top->left == NULL)
               //     return depth;
                if(top->left)
                    dq.push_back(top->left);
                if(top->right)
                    dq.push_back(top->right);
            }
          //  cout<<endl;
            dq.pop_front();
            if(!dq.empty()){
                dq.push_back(nullptr);
                depth++;
            }
        }
        return depth;
    }        
};

