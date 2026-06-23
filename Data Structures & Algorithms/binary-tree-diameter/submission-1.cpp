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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root,res);
        return res;
    }
private:
    int dfs(TreeNode *root, int& res)
    {
        if(!root) return 0;
        // left is the height of the left tree
        int left = dfs(root->left, res);
        // right is the height of the right tree
        int right = dfs(root->right, res);
        // result is max of previous res and sum of left and right tree
        res = max(res, left+ right);
        // return the height of root that would be 1 + max of left right
        return 1 + max(left,right);
    }
};
