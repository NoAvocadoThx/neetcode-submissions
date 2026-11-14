class Solution {
public:
 vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> perm;
        dfs(nums, used, perm);
        return res;
    }

    void dfs(vector<int>& nums, vector<bool>& used,  vector<int>& perm)
    {
        if(perm.size() == nums.size())
        {
            res.push_back(perm);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(!used[i])
            {
                used[i] = true;
                perm.push_back(nums[i]);
                dfs(nums, used, perm);
                used[i] =false;
                perm.pop_back();
            }
        }
    }
};
