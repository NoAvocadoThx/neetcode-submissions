class Solution {

    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size() , false);
        vector<int> perm;
        dfs(nums, perm, pick);
        return res;
    }


    void dfs(vector<int>& nums, vector<int>& perm, vector<bool>& pick)
    {
        if(perm.size() == nums.size())
        {
            res.push_back(perm);
            return;
        }

        for(int i = 0; i < nums.size() ;i ++)
        {
            if(!pick[i])
            {
                pick[i] = true;
                perm.push_back(nums[i]);
                dfs(nums, perm, pick);
                pick[i] = false;
                perm.pop_back();
            }
        }
    }
};
