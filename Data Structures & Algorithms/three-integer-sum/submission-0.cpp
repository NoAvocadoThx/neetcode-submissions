class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;// processed
            int l = i + 1;
            int r = nums.size()-1;
            int target = 0 - nums[i];
            while(l<r)
            {
                int sum = nums[l] + nums[r];
                if(sum < target)
                {
                    l++;
                }
                else if(sum > target)
                {
                    r--;
                }
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                  
                     l++;
                     r--;
                        // 内层去重：跳过和刚才相同的值
                     while (l < r && nums[l] == nums[l - 1]) l++;
                    
                }
            }
        }

        return res;
    }
};
