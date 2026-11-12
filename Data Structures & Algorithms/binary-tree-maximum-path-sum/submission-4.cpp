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
        int curMax = root->val;
        dfs(root, curMax);
        return curMax;
    }


    int dfs(TreeNode* root, int& CurMax)
    {
        if(!root) return 0;

        int leftMax = max(0, dfs(root->left, CurMax));
        int rightMax = max(0, dfs(root->right, CurMax));

        CurMax = max(CurMax, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);
    }
};
