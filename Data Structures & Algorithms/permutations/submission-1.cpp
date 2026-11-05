class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> path;
        dfs(used,path, nums);
        return res;
    }

    void dfs(vector<bool>& used, vector<int>& path, vector<int>& nums)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for(int i=0;i< nums.size();i ++)
        {
            if(!used[i])
            {
                path.push_back(nums[i]);
                used[i] = true;
                dfs(used, path, nums);
                used[i] = false;
                path.pop_back();
            }
        }
    }

};
