class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subs;
        dfs(nums,0, subs);
        return res;
    }

    void dfs(vector<int>& nums, int i, vector<int>& subs)
    {
        if(i == nums.size())
        {
            res.push_back(subs);
            return;
        }

        subs.push_back(nums[i]);
        dfs(nums, i + 1, subs);
        subs.pop_back();
        dfs(nums, i + 1, subs);
    }
};


 //                                  [1,2,3]
 //                                    []
 //                              [1]               []
  //                      [1,2]      [1]         [2]  []
 //                   [1,2,3] [1,2] [1,3] [1]   [2,3] [2]  []