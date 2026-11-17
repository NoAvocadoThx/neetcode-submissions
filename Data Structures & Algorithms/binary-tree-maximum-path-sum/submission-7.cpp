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
    int maxPathSum(TreeNode* root) {
        int res= root->val;
        dfs(root, res);
        return res;
    }


    int dfs(TreeNode* node, int& maxSoFar)
    {
        if(!node) return 0;

        int leftMax = max(0, dfs(node->left, maxSoFar));
        int rightMax = max(0, dfs(node->right, maxSoFar));

        maxSoFar = max(maxSoFar, node->val + leftMax + rightMax);

        return node->val + max(leftMax, rightMax);
    }
};
