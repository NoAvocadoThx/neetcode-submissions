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
        int res = root->val;
        dfs(root,  res );
        return res;
    }

    int dfs(TreeNode* root, int& maxSoFar)
    {
        if(!root) return 0;

        int LeftMax = max(0, dfs(root->left, maxSoFar));
        int RightMax = max(0, dfs(root->right, maxSoFar));
        maxSoFar = max( root->val + RightMax + LeftMax, maxSoFar);
        return root->val + max(LeftMax, RightMax);
    }
};



//max = curNode + leftMax + rightMax
// leftMax = max(0, dfs())

