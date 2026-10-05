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
    int maxDepth(TreeNode* root) {
        int m = 0;
        if(root == nullptr) return m;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        int count = 0;
        while(!s.empty())
        {
            pair<TreeNode*, int> cur = s.top();
            s.pop();
            TreeNode* node = cur.first;
            int depth = cur.second;
            if(node != nullptr)
            {
                m = max(m, depth);
                s.push({node->left, depth +1});
                s.push({node->right, depth + 1});
            }
            
        }
        return m;
    }
};
