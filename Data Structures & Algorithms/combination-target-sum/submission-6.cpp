class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curComb;
        dfs(nums, target, 0, curComb);
        return res;
    }

    void dfs(vector<int>& nums, int target, int i, vector<int>& comb)
    {
        if(target == 0)
        {
            res.push_back(comb);
            return;;
        }

        if(target < 0 || i >= nums.size()) return;

        comb.push_back(nums[i]);
        dfs(nums, target - nums[i], i, comb);
        comb.pop_back();
        dfs(nums, target, i + 1, comb);
    }
};
