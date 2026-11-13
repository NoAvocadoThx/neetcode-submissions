class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curSub;
        dfs(nums, 0, curSub);
        return res;
    }

    void dfs(vector<int>& nums, int i, vector<int>& curSub)
    {
        if(i == nums.size())
        {
            res.push_back(curSub);
            return;
        }

        curSub.push_back(nums[i]);
        dfs(nums, i + 1, curSub);
        curSub.pop_back();
        while( i+1 < nums.size() && nums[i] == nums[i+1])
        {
            i++;
        }
        dfs(nums, i+ 1, curSub);
    }
};
