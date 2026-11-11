class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        dfs(nums, target, 0, cur);
        return res;
    }

    void dfs(vector<int>& nums, int target, int i, vector<int>& cur)
    {
        if( target == 0)
        {
            res.push_back(cur);
            return;
        }

        if(target < 0 || i >= nums.size()) return;

        cur.push_back(nums[i]);
        dfs(nums, target - nums[i], i, cur);
        cur.pop_back();
        dfs(nums, target, i + 1, cur);
    }
};
