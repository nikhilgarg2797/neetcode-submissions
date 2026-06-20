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
private:
    int maxDepthHelper(TreeNode* root, int currDepth) {
        if (!root) return currDepth;

        return std::max(maxDepthHelper(root->left, currDepth+1), maxDepthHelper(root->right, currDepth+1));
    }
public:
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root, 0);
    }
};
