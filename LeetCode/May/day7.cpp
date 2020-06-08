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
    vector<int> par, depth;
    void parent(TreeNode *root, int d) {
        if (!root)
            return;
        depth[root->val-1]=d;
        if (root -> left)
            par[root->left->val-1]=root->val;
        if (root->right)
            par[root->right->val-1]=root->val;
        parent(root->left, d + 1);
        parent(root->right, d + 1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        par.resize(100,-1);
        depth.resize(100,0);
        parent(root, 0);
        return par[x-1]!=par[y-1]&&depth[x-1]==depth[y-1];
    }
};
