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
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }

    pair<int, bool> dfs(TreeNode* node)
    {
        if(!node) return {0, true};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        bool Balanced = left.second && right.second && (abs(left.first - right.first) <=1);
        int height = 1 + max(left.first, right.first);
        return {height, Balanced};
    }
};
