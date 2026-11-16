class Solution {
public:
 vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curSum;
        dfs(nums, target, 0, curSum);
        return res;
    }

    void dfs(vector<int>& nums, int target, int i, vector<int>& curSum)
    {
        if(target == 0)
        {
            res.push_back(curSum);
            return;
        }

        if(target < 0 || i >= nums.size()) return;
        curSum.push_back(nums[i]);
        dfs(nums, target - nums[i], i, curSum);
        curSum.pop_back();
        dfs(nums, target, i + 1, curSum);
    }
};


      