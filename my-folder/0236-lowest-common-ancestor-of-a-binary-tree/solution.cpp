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

    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> depth;

    void preprocess(TreeNode* root, TreeNode* par, int d) {
        if (!root) return;
        parent[root] = par;
        depth[root] = d;
        preprocess(root->left, root, d+1);
        preprocess(root->right, root, d+1);
    }

    TreeNode* findLCA(TreeNode* p, TreeNode* q) {
        while (p!=q) {
            if (depth[p] > depth[q]) p = parent[p];
            else q = parent[q];
        }
        return p;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        preprocess(root, NULL, 0);
        return findLCA(p, q);
        // if (root == NULL) return NULL;

        // if (root->val == p->val || root->val == q->val) return root;

        // TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // if (left && right) return root;

        // return (left) ? left : right;
    }
};
