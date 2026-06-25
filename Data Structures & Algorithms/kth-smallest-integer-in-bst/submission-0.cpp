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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int n = 0;

        while (root || !st.empty()) 
        {
            while (root) 
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            n++;
            if (n == k) return root->val;

            root = root->right;
        }

        return -1; // fallback (should not happen if k is valid)
    }
};
