class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subs;
        dfs(nums, 0 , subs);
        return res;
    }


    void dfs(vector<int>& nums, int i, vector<int>& cur)
    {
        if(i == nums.size())
        {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, i + 1, cur);
        cur.pop_back();
        while( i+1 < nums.size() && nums[i] == nums[i+1])
        {
            i++;
        }
        dfs(nums,i+1,cur);
    }
};
