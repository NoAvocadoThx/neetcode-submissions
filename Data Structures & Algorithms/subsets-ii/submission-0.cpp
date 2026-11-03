class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, {}, nums);
        return res;
    }


    void dfs(int i, vector<int> subs, vector<int>& nums)
    {
        if( i == nums.size())
        {
            res.push_back(subs);
            return;
        }

        subs.push_back(nums[i]);
        dfs(i + 1, subs, nums);
        subs.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i+1])
        {
            i++;
        }
        dfs(i+1, subs, nums);

    }
};
