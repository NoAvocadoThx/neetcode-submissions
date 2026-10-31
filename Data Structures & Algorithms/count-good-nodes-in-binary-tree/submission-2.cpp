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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

    int dfs(TreeNode* root, int maxSoFar)
    {
        if(!root) return 0;
        int res = maxSoFar <= root->val ? 1 : 0;
        maxSoFar = max(root->val, maxSoFar);
        res += dfs(root->left, maxSoFar);
        res+= dfs(root->right, maxSoFar);
        return res;  
    }
};
