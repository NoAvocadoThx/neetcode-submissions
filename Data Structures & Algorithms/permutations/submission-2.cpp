class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> perm;
        dfs(used, perm, nums);
        return res;
    }

    void dfs(vector<bool>& used, vector<int>& perm, vector<int>& nums)
    {
        if(perm.size() == nums.size())
        {
            res.push_back(perm);
            return;
        }

        for(int i=0;i< nums.size();i++)
        {
            if(!used[i])
            {
                perm.push_back(nums[i]);
                used[i] = true;
                dfs(used, perm, nums);
                used[i] = false;
                perm.pop_back();
            }
        }
    }
};
