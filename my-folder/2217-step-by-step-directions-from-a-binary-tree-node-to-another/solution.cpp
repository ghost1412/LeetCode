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

    TreeNode* findLCA (TreeNode* root, int start, int end) {
        if (root == NULL) return NULL;

        if (root->val == start || root->val == end) return root;

        TreeNode* l = findLCA(root->left, start, end);
        TreeNode* r = findLCA(root->right, start, end);

        if (l && r) return root;

        return (l) ? l : r;
    }

    bool pathToNode(TreeNode* root, int nodeValue, string& path, bool upRoute) {
        if (root == NULL) return false;
        if (root->val == nodeValue) {
            return true;
        }

        bool route = false;
        if (!upRoute) {
            path += 'L';
            route = pathToNode(root->left, nodeValue, path, upRoute);
            if (route) return true;
            path.pop_back();
            path +='R';
            route = pathToNode(root->right, nodeValue, path, upRoute);
            if (route) return true;
            path.pop_back();
            return false;
        } else {
            path +='U';
            route = pathToNode(root->left, nodeValue, path, upRoute);
            if (route) return route;
            route = pathToNode(root->right, nodeValue, path, upRoute);
            if (route) return route;
            path.pop_back();
            return false;
        }

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        string leftRoute = "", rightRoute = "";
        pathToNode(lca, startValue, leftRoute, true);
        pathToNode(lca, destValue, rightRoute, false);
        return leftRoute + rightRoute;
    }
};
